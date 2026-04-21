#include <iostream>
#include <fstream>
#include "system.h"
using namespace std;


int main(){
	cout << "input simulation size" << endl;
	int N_size;
	try {
		cin >> N_size;
	} catch (...) {
		return 1;
	}
	cout << "input magnetic field" << endl;
	double H;
	try {
		cin >> H;
	} catch (...) {
		return 1;
	}
	cout << "input temperature(K)" << endl;
	double temp;
	try {
		cin >> temp;
	} catch (...) {
		return 1;
	}
	cout << "input simulationcycle" << endl;
	int Cyc;
	try {
		cin >> Cyc;
	} catch (...) {
		return 1;
	}

	double h_eff = H*mu_avog;

	objSystem simulation_system(H,0.0,temp,N_size);

	vector<double> energy_step(Cyc,-1.0);
	for(int i = 0; i < Cyc; i++){
		simulation_system.gibbs_sampling();
		energy_step.at(i) = simulation_system.calculationEnergy();
	}

	ofstream result("energy.dat");
	for(int i = 0; i < Cyc; i++){
		result << i << " " << energy_step.at(i) << endl;
	}

	result.close();



	return 0;
}
