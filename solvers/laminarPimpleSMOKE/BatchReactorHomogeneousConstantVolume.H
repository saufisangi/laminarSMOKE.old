
#ifndef BatchReactorHomogeneousConstantVolume_H
#define	BatchReactorHomogeneousConstantVolume_H

class BatchReactorHomogeneousConstantVolume
{
public:

	BatchReactorHomogeneousConstantVolume(	OpenSMOKE::ThermodynamicsMap_CHEMKIN<double>& thermodynamicsMap, 
					OpenSMOKE::KineticsMap_CHEMKIN<double>& kineticsMap);

	void SetReactor( const double V0, const double P0, const double rho0);
	
	void SetEnergyEquation(const bool flag) { energyEquation_ = flag; }
	
	void SetCheckMassFractions( const bool flag ) { checkMassFractions_ = flag; };

	const OpenSMOKE::OpenSMOKEVectorDouble& R() const { return R_; }
	double QR() const { return QR_; }

	unsigned int NumberOfEquations() { return NE_; }

	virtual int Equations(const double t, const OpenSMOKE::OpenSMOKEVectorDouble& y, OpenSMOKE::OpenSMOKEVectorDouble& dy);

	virtual int Print(const double t, const OpenSMOKE::OpenSMOKEVectorDouble& y);

private:

	double T_;
	double P_;
	double V0_;
	double rho0_;

	double cTot_;
	double MW_;
	double CvMixMass_;
	double QR_;

	unsigned int NC_;
	unsigned int NE_;

	OpenSMOKE::ThermodynamicsMap_CHEMKIN<double>&	thermodynamicsMap_;		//!< thermodynamic map
	OpenSMOKE::KineticsMap_CHEMKIN<double>&		kineticsMap_;			//!< kinetic map

	OpenSMOKE::OpenSMOKEVectorDouble omega_;
	OpenSMOKE::OpenSMOKEVectorDouble x_;
	OpenSMOKE::OpenSMOKEVectorDouble c_;
	OpenSMOKE::OpenSMOKEVectorDouble R_;
	
	bool checkMassFractions_;
	bool energyEquation_;
};

BatchReactorHomogeneousConstantVolume::BatchReactorHomogeneousConstantVolume(	OpenSMOKE::ThermodynamicsMap_CHEMKIN<double>& thermodynamicsMap, 
								OpenSMOKE::KineticsMap_CHEMKIN<double>& kineticsMap):
	thermodynamicsMap_(thermodynamicsMap), 
	kineticsMap_(kineticsMap)
	{
		NC_ = thermodynamicsMap_.NumberOfSpecies();
		NE_ = NC_+1;
		QR_ = 0.;
		
		ChangeDimensions(NC_, &omega_, true);
		ChangeDimensions(NC_, &x_, true);
		ChangeDimensions(NC_, &c_, true);
		ChangeDimensions(NC_, &R_, true);
		
		checkMassFractions_ = false;
		energyEquation_ = true;
	}

void BatchReactorHomogeneousConstantVolume::SetReactor( const double V0, const double P0, const double rho0)
{
	P_    = P0;
	V0_   = V0;
	rho0_ = rho0;
}

int BatchReactorHomogeneousConstantVolume::Equations(const double t, const OpenSMOKE::OpenSMOKEVectorDouble& y, OpenSMOKE::OpenSMOKEVectorDouble& dy)
{
	// Recover mass fractions
	if (checkMassFractions_ == true)
	{	for(unsigned int i=1;i<=NC_;++i)
			omega_[i] = max(y[i], 0.);
	}
	else
	{
		for(unsigned int i=1;i<=NC_;++i)
			omega_[i] = y[i];
	}

	// Recover temperature
	T_ = y[NC_+1];

	// Calculates the pressure and the concentrations of species
	thermodynamicsMap_.MoleFractions_From_MassFractions(x_, MW_, omega_);
	cTot_ = rho0_/MW_;
	Product(cTot_, x_, &c_);
	P_ = cTot_ * PhysicalConstants::R_J_kmol * T_;

	// Calculates thermodynamic properties
	thermodynamicsMap_.SetTemperature(T_);
	thermodynamicsMap_.SetPressure(P_);
	
	// Calculates kinetics
	kineticsMap_.SetTemperature(T_);
	kineticsMap_.SetPressure(P_);
	kineticsMap_.KineticConstants();
	kineticsMap_.ReactionRates(c_);
	kineticsMap_.FormationRates(&R_);
	
	// Species equations
	for (unsigned int i=1;i<=NC_;++i)	
		dy[i] = thermodynamicsMap_.MW()[i]*R_[i]/rho0_;
                
    // Energy equation
    dy[NC_+1] = 0.;   
    if (energyEquation_ == true)
    {
		double CpMixMolar; 
		thermodynamicsMap_.cpMolar_Mixture_From_MoleFractions(CpMixMolar,x_);
		CvMixMass_ = (CpMixMolar - PhysicalConstants::R_J_kmol) / MW_;
	
		QR_ = kineticsMap_.HeatRelease(R_);
		const double sumMoleFormationRates = R_.SumElements();
		
		dy[NC_+1]  = (QR_ + PhysicalConstants::R_J_kmol*T_*sumMoleFormationRates) / (rho0_*CvMixMass_);
	}
	
	return 0;
}

int BatchReactorHomogeneousConstantVolume::Print(const double t, const OpenSMOKE::OpenSMOKEVectorDouble& y)
{
}

#endif // BatchReactorHomogeneousConstantVolume_H
