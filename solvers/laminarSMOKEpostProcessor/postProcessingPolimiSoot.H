// Post processing: soot (Polimi)
if (iPolimiSoot == true)
{
	volScalarField soot_fv_large
	(
		IOobject
		(
			"soot::fv_large",
			mesh.time().timeName(),
			mesh,
			IOobject::NO_READ,
			IOobject::NO_WRITE
		),
		mesh,
		dimensionSet(0, 0, 0, 0, 0)
	);
	volScalarField soot_fv_small
	(
		IOobject
		(
			"soot::fv_small",
			mesh.time().timeName(),
			mesh,
			IOobject::NO_READ,
			IOobject::NO_WRITE
		),
		mesh,
		dimensionSet(0, 0, 0, 0, 0)
	);
	volScalarField soot_rho_large
	(
		IOobject
		(
			"soot::rho_large",
			mesh.time().timeName(),
			mesh,
			IOobject::NO_READ,
			IOobject::NO_WRITE
		),
		mesh,
		dimensionSet(1, -3, 0, 0, 0)
	);
	volScalarField soot_rho_small
	(
		IOobject
		(
			"soot::rho_small",
			mesh.time().timeName(),
			mesh,
			IOobject::NO_READ,
			IOobject::NO_WRITE
		),
		mesh,
		dimensionSet(1, -3, 0, 0, 0)
	);
	volScalarField soot_N_large
	(
		IOobject
		(
			"soot::N_large",
			mesh.time().timeName(),
			mesh,
			IOobject::NO_READ,
			IOobject::NO_WRITE
		),
		mesh,
		dimensionSet(0, -3, 0, 0, 0)
	);
	volScalarField soot_N_small
	(
		IOobject
		(
			"soot::N_small",
			mesh.time().timeName(),
			mesh,
			IOobject::NO_READ,
			IOobject::NO_WRITE
		),
		mesh,
		dimensionSet(0, -3, 0, 0, 0)
	);
	volScalarField soot_omega_large
	(
		IOobject
		(
			"soot::omega_large",
			mesh.time().timeName(),
			mesh,
			IOobject::NO_READ,
			IOobject::NO_WRITE
		),
		mesh,
		dimensionSet(0, 0, 0, 0, 0)
	);
	volScalarField soot_omega_small
	(
		IOobject
		(
			"soot::omega_small",
			mesh.time().timeName(),
			mesh,
			IOobject::NO_READ,
			IOobject::NO_WRITE
		),
		mesh,
		dimensionSet(0, 0, 0, 0, 0)
	);
	volScalarField soot_x_large
	(
		IOobject
		(
			"soot::x_large",
			mesh.time().timeName(),
			mesh,
			IOobject::NO_READ,
			IOobject::NO_WRITE
		),
		mesh,
		dimensionSet(0, 0, 0, 0, 0)
	);
	volScalarField soot_x_small
	(
		IOobject
		(
			"soot::x_small",
			mesh.time().timeName(),
			mesh,
			IOobject::NO_READ,
			IOobject::NO_WRITE
		),
		mesh,
		dimensionSet(0, 0, 0, 0, 0)
	);
	volScalarField soot_h_over_c_large
	(
		IOobject
		(
			"soot::h_over_c_large",
			mesh.time().timeName(),
			mesh,
			IOobject::NO_READ,
			IOobject::NO_WRITE
		),
		mesh,
		dimensionSet(0, 0, 0, 0, 0)
	);
	volScalarField soot_h_over_c_small
	(
		IOobject
		(
			"soot::h_over_c_small",
			mesh.time().timeName(),
			mesh,
			IOobject::NO_READ,
			IOobject::NO_WRITE
		),
		mesh,
		dimensionSet(0, 0, 0, 0, 0)
	);
	volScalarField soot_o_over_c_large
	(
		IOobject
		(
			"soot::o_over_c_large",
			mesh.time().timeName(),
			mesh,
			IOobject::NO_READ,
			IOobject::NO_WRITE
		),
		mesh,
		dimensionSet(0, 0, 0, 0, 0)
	);
	volScalarField soot_o_over_c_small
	(
		IOobject
		(
			"soot::o_over_c_small",
			mesh.time().timeName(),
			mesh,
			IOobject::NO_READ,
			IOobject::NO_WRITE
		),
		mesh,
		dimensionSet(0, 0, 0, 0, 0)
	);
	volScalarField soot_o_over_h_large
	(
		IOobject
		(
			"soot::o_over_h_large",
			mesh.time().timeName(),
			mesh,
			IOobject::NO_READ,
			IOobject::NO_WRITE
		),
		mesh,
		dimensionSet(0, 0, 0, 0, 0)
	);
	volScalarField soot_o_over_h_small
	(
		IOobject
		(
			"soot::o_over_h_small",
			mesh.time().timeName(),
			mesh,
			IOobject::NO_READ,
			IOobject::NO_WRITE
		),
		mesh,
		dimensionSet(0, 0, 0, 0, 0)
	);

        volScalarField soot_omega_precursors
	(
		IOobject
		(
			"soot::omega_precursors",
			mesh.time().timeName(),
			mesh,
			IOobject::NO_READ,
			IOobject::NO_WRITE
		),
		mesh,
		dimensionSet(0, 0, 0, 0, 0)
	);

        volScalarField soot_x_precursors
	(
		IOobject
		(
			"soot::x_precursors",
			mesh.time().timeName(),
			mesh,
			IOobject::NO_READ,
			IOobject::NO_WRITE
		),
		mesh,
		dimensionSet(0, 0, 0, 0, 0)
	);

	volScalarField soot_R_large
	(
		IOobject
		(
			"soot::R_large",
			mesh.time().timeName(),
			mesh,
			IOobject::NO_READ,
			IOobject::AUTO_WRITE
		),
		mesh,
		dimensionSet(1, -3, -1, 0, 0)
	);

	volScalarField soot_R_small
	(
		IOobject
		(
			"soot::R_small",
			mesh.time().timeName(),
			mesh,
			IOobject::NO_READ,
			IOobject::AUTO_WRITE
		),
		mesh,
		dimensionSet(1, -3, -1, 0, 0)
	);

 	volScalarField pah_R_1_2
	(
		IOobject
		(
			"pah::R_1_2",
			mesh.time().timeName(),
			mesh,
			IOobject::NO_READ,
			IOobject::AUTO_WRITE
		),
		mesh,
		dimensionSet(1, -3, -1, 0, 0)
	);

	volScalarField pah_R_3_4
	(
		IOobject
		(
			"pah::R_3_4",
			mesh.time().timeName(),
			mesh,
			IOobject::NO_READ,
			IOobject::AUTO_WRITE
		),
		mesh,
		dimensionSet(1, -3, -1, 0, 0)
	);

	volScalarField pah_R_more_4
	(
		IOobject
		(
			"pah::R_more_4",
			mesh.time().timeName(),
			mesh,
			IOobject::NO_READ,
			IOobject::AUTO_WRITE
		),
		mesh,
		dimensionSet(1, -3, -1, 0, 0)
	);

	Info << "Post processing soot..." << endl;

	label ns = Y.size();

	OpenSMOKE::OpenSMOKEVectorDouble y(ns);
	OpenSMOKE::OpenSMOKEVectorDouble x(ns);
	OpenSMOKE::OpenSMOKEVectorDouble c(thermodynamicsMapXML->NumberOfSpecies());
	OpenSMOKE::OpenSMOKEVectorDouble R(thermodynamicsMapXML->NumberOfSpecies());
	Eigen::VectorXd y_eigen(ns);
	Eigen::VectorXd x_eigen(ns);

	const scalarField& TCells = T.internalField();
	const scalarField& pCells = p.internalField();

	scalarField& soot_fv_largeCells = soot_fv_large.internalField();
	scalarField& soot_fv_smallCells = soot_fv_small.internalField();
	scalarField& soot_rho_largeCells = soot_rho_large.internalField();
	scalarField& soot_rho_smallCells = soot_rho_small.internalField();
	scalarField& soot_N_largeCells = soot_N_large.internalField();
	scalarField& soot_N_smallCells = soot_N_small.internalField();
	scalarField& soot_x_largeCells = soot_x_large.internalField();
	scalarField& soot_x_smallCells = soot_x_small.internalField();
	scalarField& soot_omega_largeCells = soot_omega_large.internalField();
	scalarField& soot_omega_smallCells = soot_omega_small.internalField();
	scalarField& soot_h_over_c_largeCells = soot_h_over_c_large.internalField();
	scalarField& soot_h_over_c_smallCells = soot_h_over_c_small.internalField();
	scalarField& soot_o_over_c_largeCells = soot_o_over_c_large.internalField();
	scalarField& soot_o_over_c_smallCells = soot_o_over_c_small.internalField();
	scalarField& soot_o_over_h_largeCells = soot_o_over_h_large.internalField();
	scalarField& soot_o_over_h_smallCells = soot_o_over_h_small.internalField();
	scalarField& soot_omega_precursorsCells = soot_omega_precursors.internalField();
	scalarField& soot_x_precursorsCells = soot_x_precursors.internalField();

	scalarField& soot_R_largeCells = soot_R_large.internalField();
	scalarField& soot_R_smallCells = soot_R_small.internalField();
	scalarField& pah_R_1_2Cells = pah_R_1_2.internalField();
	scalarField& pah_R_3_4Cells = pah_R_3_4.internalField();
	scalarField& pah_R_more_4Cells = pah_R_more_4.internalField();

	forAll(TCells, celli)
	{	
		double mw;

		// Extract the mean mass fractions
		for(unsigned int i=0;i<ns;i++)
			y[i+1] = Y[i].internalField()[celli];
		const double sum = y.SumElements();
		for(unsigned int i=0;i<ns;i++)
			y[i+1] /= sum;
		

		// Molecular weight
		thermodynamicsMapXML->MoleFractions_From_MassFractions(x, mw, y);

		// Eigen vectors
		for(unsigned int i=0;i<ns;i++)
		{
			y_eigen(i) = y[i+1];
			x_eigen(i) = x[i+1];
		}

		// Density
		const double rhoGas = pCells[celli]*mw/PhysicalConstants::R_J_kmol/TCells[celli];

		// Soot analysis
		sootAnalyzer->Analysis(TCells[celli], pCells[celli], rhoGas, y_eigen, x_eigen);
		soot_fv_largeCells[celli] = sootAnalyzer->fv_large();
		soot_fv_smallCells[celli] = sootAnalyzer->fv_small();
		soot_rho_largeCells[celli] = sootAnalyzer->rho_large();
		soot_rho_smallCells[celli] = sootAnalyzer->rho_small();
		soot_N_largeCells[celli] = sootAnalyzer->N_large();
		soot_N_smallCells[celli] = sootAnalyzer->N_small();
		soot_omega_largeCells[celli] = sootAnalyzer->omega_large();
		soot_omega_smallCells[celli] = sootAnalyzer->omega_small();
		soot_x_largeCells[celli] = sootAnalyzer->x_large();
		soot_x_smallCells[celli] = sootAnalyzer->x_small();
		soot_h_over_c_largeCells[celli] = sootAnalyzer->h_over_c_large();
		soot_h_over_c_smallCells[celli] = sootAnalyzer->h_over_c_small();
		soot_o_over_c_largeCells[celli] = sootAnalyzer->o_over_c_large();
		soot_o_over_c_smallCells[celli] = sootAnalyzer->o_over_c_small();
		soot_o_over_h_largeCells[celli] = sootAnalyzer->o_over_h_large();
		soot_o_over_h_smallCells[celli] = sootAnalyzer->o_over_h_small();

		soot_omega_precursorsCells[celli] = 0.;
		soot_x_precursorsCells[celli] = 0.;
		for(unsigned int k=0;k<soot_precursors_indices.size();k++)
		{
			int index = soot_precursors_indices[k];
			soot_omega_precursorsCells[celli] += y_eigen(index);
			soot_x_precursorsCells[celli] += x_eigen(index);
		}

		// Concentrations
		const double cTot = pCells[celli]/PhysicalConstants::R_J_kmol/TCells[celli];
		Product(cTot,x, &c);

		// Kinetics
		kineticsMapXML->SetTemperature(TCells[celli]);
		kineticsMapXML->SetPressure(pCells[celli]);
		kineticsMapXML->KineticConstants();
		kineticsMapXML->ReactionRates(c);
		kineticsMapXML->FormationRates(&R);
		for(unsigned int i=1;i<=ns;i++)
			R[i] *= thermodynamicsMapXML->MW()[i];

		soot_R_largeCells[celli] = largeBinMassFormationRates(sootAnalyzer, R);
		soot_R_smallCells[celli] = smallBinMassFormationRates(sootAnalyzer, R);
		pah_R_1_2Cells[celli]    = pah12RingsFormationRates(sootAnalyzer, R);
		pah_R_3_4Cells[celli]    = pah34RingsFormationRates(sootAnalyzer, R);
		pah_R_more_4Cells[celli] = pahMoreThan4RingsFormationRates(sootAnalyzer, R);			
	}

	forAll(T.boundaryField(), patchi)
	{
		const fvPatchScalarField& pT  = T.boundaryField()[patchi];
		const fvPatchScalarField& pp  = p.boundaryField()[patchi];
		
		fvPatchScalarField& psoot_fv_large = soot_fv_large.boundaryField()[patchi];
		fvPatchScalarField& psoot_fv_small = soot_fv_small.boundaryField()[patchi];
		fvPatchScalarField& psoot_rho_large = soot_rho_large.boundaryField()[patchi];
		fvPatchScalarField& psoot_rho_small = soot_rho_small.boundaryField()[patchi];
		fvPatchScalarField& psoot_N_large = soot_N_large.boundaryField()[patchi];
		fvPatchScalarField& psoot_N_small = soot_N_small.boundaryField()[patchi];
		fvPatchScalarField& psoot_omega_large = soot_omega_large.boundaryField()[patchi];
		fvPatchScalarField& psoot_omega_small = soot_omega_small.boundaryField()[patchi];
		fvPatchScalarField& psoot_x_large = soot_x_large.boundaryField()[patchi];
		fvPatchScalarField& psoot_x_small = soot_x_small.boundaryField()[patchi];
		fvPatchScalarField& psoot_h_over_c_large = soot_h_over_c_large.boundaryField()[patchi];
		fvPatchScalarField& psoot_h_over_c_small = soot_h_over_c_small.boundaryField()[patchi];
		fvPatchScalarField& psoot_o_over_c_large = soot_o_over_c_large.boundaryField()[patchi];
		fvPatchScalarField& psoot_o_over_c_small = soot_o_over_c_small.boundaryField()[patchi];
		fvPatchScalarField& psoot_o_over_h_large = soot_o_over_h_large.boundaryField()[patchi];
		fvPatchScalarField& psoot_o_over_h_small = soot_o_over_h_small.boundaryField()[patchi];
		fvPatchScalarField& psoot_x_precursors = soot_x_precursors.boundaryField()[patchi];
		fvPatchScalarField& psoot_omega_precursors = soot_omega_precursors.boundaryField()[patchi];

		fvPatchScalarField& psoot_R_large = soot_R_large.boundaryField()[patchi];
		fvPatchScalarField& psoot_R_small = soot_R_small.boundaryField()[patchi];
		fvPatchScalarField& ppah_R_1_2 = pah_R_1_2.boundaryField()[patchi];
		fvPatchScalarField& ppah_R_3_4 = pah_R_3_4.boundaryField()[patchi];
		fvPatchScalarField& ppah_R_more_4 = pah_R_more_4.boundaryField()[patchi];


		forAll(pT, facei)
		{
			double mw;

			// Extract the mass fractions
			for(unsigned int i=0;i<ns;i++)
				y[i+1] = Y[i].boundaryField()[patchi][facei];
			const double sum = y.SumElements();
			for(unsigned int i=0;i<ns;i++)
				y[i+1] /= sum;

			// Molecular weight
			thermodynamicsMapXML->MoleFractions_From_MassFractions(x, mw, y);

			// Eigen vectors
			for(unsigned int i=0;i<ns;i++)
			{
				y_eigen(i) = y[i+1];
				x_eigen(i) = x[i+1];
			}

			// Density
			const double rhoGas = pp[facei]*mw/PhysicalConstants::R_J_kmol/pT[facei];

			// Soot analysis
			sootAnalyzer->Analysis(pT[facei], pp[facei], rhoGas, y_eigen, x_eigen);	
			psoot_fv_large[facei] = sootAnalyzer->fv_large();
			psoot_fv_small[facei] = sootAnalyzer->fv_small();
			psoot_rho_large[facei] = sootAnalyzer->rho_large();
			psoot_rho_small[facei] = sootAnalyzer->rho_small();
			psoot_N_large[facei] = sootAnalyzer->N_large();
			psoot_N_small[facei] = sootAnalyzer->N_small();
			psoot_omega_large[facei] = sootAnalyzer->omega_large();
			psoot_omega_small[facei] = sootAnalyzer->omega_small();
			psoot_x_large[facei] = sootAnalyzer->x_large();
			psoot_x_small[facei] = sootAnalyzer->x_small();
			psoot_h_over_c_large[facei] = sootAnalyzer->h_over_c_large();
			psoot_h_over_c_small[facei] = sootAnalyzer->h_over_c_small();
			psoot_o_over_c_large[facei] = sootAnalyzer->o_over_c_large();
			psoot_o_over_c_small[facei] = sootAnalyzer->o_over_c_small();
			psoot_o_over_h_large[facei] = sootAnalyzer->o_over_h_large();
			psoot_o_over_h_small[facei] = sootAnalyzer->o_over_h_small();

			// Soot precursors
        		psoot_omega_precursors[facei] = 0.;
			psoot_x_precursors[facei] = 0.;
			for(unsigned int k=0;k<soot_precursors_indices.size();k++)
			{
				int index = soot_precursors_indices[k];
				psoot_omega_precursors[facei] += y_eigen(index);
				psoot_x_precursors[facei] += x_eigen(index);
			}

			// Concentrations
			const double cTot = pp[facei]/PhysicalConstants::R_J_kmol/pT[facei];
			Product(cTot,x, &c);

			// Kinetics
			kineticsMapXML->SetTemperature(pT[facei]);
			kineticsMapXML->SetPressure(pp[facei]);
			kineticsMapXML->KineticConstants();
			kineticsMapXML->ReactionRates(c);
			kineticsMapXML->FormationRates(&R);
			for(unsigned int i=1;i<=ns;i++)
				R[i] *= thermodynamicsMapXML->MW()[i];

			psoot_R_large[facei] = largeBinMassFormationRates(sootAnalyzer, R);
			psoot_R_small[facei] = smallBinMassFormationRates(sootAnalyzer, R);
			ppah_R_1_2[facei]    = pah12RingsFormationRates(sootAnalyzer, R);
			ppah_R_3_4[facei]    = pah34RingsFormationRates(sootAnalyzer, R);
			ppah_R_more_4[facei] = pahMoreThan4RingsFormationRates(sootAnalyzer, R);
		}
	}

	soot_fv_large.write();	
	soot_fv_small.write();
	soot_rho_large.write();	
	soot_rho_small.write();	
	soot_N_large.write();	
	soot_N_small.write();	
	soot_omega_large.write();	
	soot_omega_small.write();
	soot_x_large.write();	
	soot_x_small.write();
	soot_h_over_c_large.write();
	soot_h_over_c_small.write();
	soot_o_over_c_large.write();
	soot_o_over_c_small.write();
	soot_o_over_h_large.write();
	soot_o_over_h_small.write();	
	soot_omega_precursors.write();
	soot_x_precursors.write();

	soot_R_large.write();
	soot_R_small.write();
	pah_R_1_2.write();
	pah_R_3_4.write();
	pah_R_more_4.write();


	// Distribution along a boundary
	for (int i=0;i<polimiSootBoundaries.size();i++)
	{
		label patchi = mesh.boundaryMesh().findPatchID(polimiSootBoundaries[i]); 

		const fvPatchScalarField& pT  = T.boundaryField()[patchi];
		const fvPatchScalarField& pp  = p.boundaryField()[patchi];
		const vectorField& faceCentres = mesh.Cf().boundaryField()[patchi];

		const std::string file_name = "SootDistribution." + polimiSootBoundaries[i] + ".out";
		std::ofstream fOutput(file_name.c_str(), std::ios::out);
		fOutput.setf(std::ios::scientific);
		sootAnalyzer->WriteDistributionLabel(fOutput);

		forAll(pT, facei)
		{
			
			scalar face_x = faceCentres[facei].x();
			scalar face_y = faceCentres[facei].y();
			scalar face_z = faceCentres[facei].z();

			double mw;

			// Extract the mass fractions
			for(unsigned int i=0;i<ns;i++)
				y[i+1] = Y[i].boundaryField()[patchi][facei];
			const double sum = y.SumElements();
			for(unsigned int i=0;i<ns;i++)
				y[i+1] /= sum;
	
			// Molecular weight
			thermodynamicsMapXML->MoleFractions_From_MassFractions(x, mw, y);

			// Eigen vectors
			for(unsigned int i=0;i<ns;i++)
			{
				y_eigen(i) = y[i+1];
				x_eigen(i) = x[i+1];
			}

			// Density
			const double rhoGas = pp[facei]*mw/PhysicalConstants::R_J_kmol/pT[facei];

			// Soot analysis
			sootAnalyzer->Analysis(pT[facei], pp[facei], rhoGas, y_eigen, x_eigen);	
			sootAnalyzer->Distribution();
			sootAnalyzer->WriteDistribution(fOutput, face_x, 0., 0., pT[facei]);
		}
		
		fOutput.close();
	}

	// Distribution in a specific point
	if (pnts_soot_psdf.size() > 0)
	{
		Info << "Post processing PSDF..." << endl;

		for (unsigned int i=0;i<pnts_soot_psdf.size();i++)
		{
			const double xx = pnts_soot_psdf[i][0];
			const double yy = pnts_soot_psdf[i][1];
			const double zz = pnts_soot_psdf[i][2];

			Info << "Post processing point " << i+1 << " @ " << xx << " " << yy << " " << zz << endl;

			vector pos(xx,yy,zz);
			label cellI = mesh.findCell(pos);

			if (cellI > -1)
			{
				std::stringstream tag;
				tag << i;
				std::string name_file = "/soot::PSDF_" + tag.str();

				// File name
				fileName outputFile(runTime.path()/runTime.timeName()/name_file.c_str());
				std::ofstream fOutput(outputFile.c_str(), std::ios::out);
				fOutput.setf(std::ios::scientific);
				sootAnalyzer->WriteDistributionLabel(fOutput);

				// Temperature and pressure
				autoPtr<interpolation<scalar> > Tinterp = interpolation<scalar>::New("cellPoint", T);
				scalar Tint = Tinterp->interpolate(pos, cellI);
				autoPtr<interpolation<scalar> > pinterp = interpolation<scalar>::New("cellPoint", p);
				scalar pint = pinterp->interpolate(pos, cellI);

				Info << "Cell: " << cellI << " T: " << Tint << " P: " << pint << endl; 


				double mw;

				// Extract the mass fractions
				for(unsigned int i=0;i<ns;i++)
				{
					autoPtr<interpolation<scalar> > Yinterp = interpolation<scalar>::New("cellPoint", Y[i]);
					y[i+1] = Yinterp->interpolate(pos, cellI);
				}

				const double sum = y.SumElements();
				for(unsigned int i=0;i<ns;i++)
					y[i+1] /= sum;

				// Molecular weight
				thermodynamicsMapXML->MoleFractions_From_MassFractions(x, mw, y);

				// Eigen vectors
				for(unsigned int i=0;i<ns;i++)
				{
					y_eigen(i) = y[i+1];
					x_eigen(i) = x[i+1];
				}

				// Density
				const double rhoGas = pint*mw/PhysicalConstants::R_J_kmol/Tint;

				// Soot analysis
				sootAnalyzer->Analysis(Tint, pint, rhoGas, y_eigen, x_eigen);	
				sootAnalyzer->Distribution();
				sootAnalyzer->WriteDistribution(fOutput, xx, yy, zz, Tint);
				fOutput.close();
			}
		}
	}
}
