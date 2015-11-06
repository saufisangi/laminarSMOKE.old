if (iPolimiSoot == true)
{
	// Soot Analysis
	if (sootOnTheFlyFill == true && runTime.outputTime() == true)
	{
		Info<< "On the fly soot post processing... ";
		
		double tStart = OpenSMOKE::OpenSMOKEGetCpuTime();

		label ns = Y.size();

		OpenSMOKE::OpenSMOKEVectorDouble y(ns);
		OpenSMOKE::OpenSMOKEVectorDouble x(ns);
		Eigen::VectorXd y_eigen(ns);
		Eigen::VectorXd x_eigen(ns);

		const scalarField& TCells = T.internalField();
		const scalarField& pCells = p.internalField();

		scalarField& soot_fv_largeCells = sootFields[0].internalField();
		scalarField& soot_fv_smallCells = sootFields[1].internalField();
		scalarField& soot_rho_largeCells = sootFields[2].internalField();
		scalarField& soot_rho_smallCells = sootFields[3].internalField();
		scalarField& soot_N_largeCells = sootFields[4].internalField();
		scalarField& soot_N_smallCells = sootFields[5].internalField();
		scalarField& soot_x_largeCells = sootFields[6].internalField();
		scalarField& soot_x_smallCells = sootFields[7].internalField();
		scalarField& soot_omega_largeCells = sootFields[8].internalField();
		scalarField& soot_omega_smallCells = sootFields[9].internalField();
		scalarField& pah_omega_1_2_smallCells = sootFields[10].internalField();
		scalarField& pah_omega_3_4_smallCells = sootFields[11].internalField();
		scalarField& pah_omega_more_4_smallCells = sootFields[12].internalField();


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
			pah_omega_1_2_smallCells[celli] = sootAnalyzer->omega_pah_1_2_rings();
			pah_omega_3_4_smallCells[celli] = sootAnalyzer->omega_pah_3_4_rings();
			pah_omega_more_4_smallCells[celli] = sootAnalyzer->omega_pah_more_than_4_rings();
		}

		forAll(T.boundaryField(), patchi)
		{
			const fvPatchScalarField& pT  = T.boundaryField()[patchi];
			const fvPatchScalarField& pp  = p.boundaryField()[patchi];
		
			fvPatchScalarField& psoot_fv_large = sootFields[0].boundaryField()[patchi];
			fvPatchScalarField& psoot_fv_small = sootFields[1].boundaryField()[patchi];
			fvPatchScalarField& psoot_rho_large = sootFields[2].boundaryField()[patchi];
			fvPatchScalarField& psoot_rho_small = sootFields[3].boundaryField()[patchi];
			fvPatchScalarField& psoot_N_large = sootFields[4].boundaryField()[patchi];
			fvPatchScalarField& psoot_N_small = sootFields[5].boundaryField()[patchi];
			fvPatchScalarField& psoot_x_large = sootFields[6].boundaryField()[patchi];
			fvPatchScalarField& psoot_x_small = sootFields[7].boundaryField()[patchi];
			fvPatchScalarField& psoot_omega_large = sootFields[8].boundaryField()[patchi];
			fvPatchScalarField& psoot_omega_small = sootFields[9].boundaryField()[patchi];
			fvPatchScalarField& ppah_omega_1_2 = sootFields[10].boundaryField()[patchi];
			fvPatchScalarField& ppah_omega_3_4 = sootFields[11].boundaryField()[patchi];
			fvPatchScalarField& ppah_omega_more_4 = sootFields[12].boundaryField()[patchi];

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
				ppah_omega_1_2[facei] = sootAnalyzer->omega_pah_1_2_rings();
				ppah_omega_3_4[facei] = sootAnalyzer->omega_pah_3_4_rings();
				ppah_omega_more_4[facei] = sootAnalyzer->omega_pah_more_than_4_rings();
			}
		}

		double tEnd = OpenSMOKE::OpenSMOKEGetCpuTime();

		Info << "done in " << tEnd - tStart << " s  (" << (tEnd-tStart)/double(mesh.nCells())*1000. << " ms per cell)" << endl;
	}

	if (sootIntegralCounter == sootIntegralUpdate)
	{
		const double large_bin_mass = largeBinMass(sootAnalyzer, rho, Y);
		const double small_bin_mass = smallBinMass(sootAnalyzer, rho, Y);
		const double large_bin_volume = largeBinVolume(sootAnalyzer, rho, Y);
		const double small_bin_volume = smallBinVolume(sootAnalyzer, rho, Y);
		const double large_bin_particles = largeBinNumberParticles(sootAnalyzer, rho, Y);
		const double small_bin_particles = smallBinNumberParticles(sootAnalyzer, rho, Y);
		const double soot_dimer_mass = sootDimerMass(sootAnalyzer, rho, Y);
		const double pah_1_2_rings_mass = pah_1_2_rings_Mass(sootAnalyzer, rho, Y);
		const double pah_3_4_rings_mass = pah_3_4_rings_Mass(sootAnalyzer, rho, Y);
		const double pah_more_than_4_rings_mass = pah_more_than_4_rings_Mass(sootAnalyzer, rho, Y);
		
		*fSootIntegrals << std::setw(20) << runTime.value();
		*fSootIntegrals << std::setw(20) << large_bin_mass;
		*fSootIntegrals << std::setw(20) << large_bin_volume;
		*fSootIntegrals << std::setw(20) << large_bin_particles;		
		*fSootIntegrals << std::setw(20) << small_bin_mass;
		*fSootIntegrals << std::setw(20) << small_bin_volume;
		*fSootIntegrals << std::setw(20) << small_bin_particles;
		*fSootIntegrals << std::setw(20) << soot_dimer_mass;		
		*fSootIntegrals << std::setw(20) << pah_1_2_rings_mass;
		*fSootIntegrals << std::setw(20) << pah_3_4_rings_mass;
		*fSootIntegrals << std::setw(20) << pah_more_than_4_rings_mass;
		*fSootIntegrals << std::endl;

		Info << "Soot mass:            " << large_bin_mass << endl;
		Info << "Soot volume:          " << large_bin_volume << endl;
		Info << "Soot particles:       " << large_bin_particles << endl;		
		Info << "Precursors mass:      " << small_bin_mass << endl;
		Info << "Precursors volume:    " << small_bin_volume << endl;
		Info << "Precursors particles: " << small_bin_particles << endl;
		Info << "Dimer mass:           " << soot_dimer_mass << endl;		
		Info << "PAH(340) mass:        " << pah_1_2_rings_mass << endl;
		Info << "PAH(400) mass:        " << pah_3_4_rings_mass << endl;
		Info << "PAH(500) mass:        " << pah_more_than_4_rings_mass << endl;

		sootIntegralCounter = 0;
	}

	sootIntegralCounter++;
}