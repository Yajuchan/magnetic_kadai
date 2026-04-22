//#include <iostream>
#include <fstream>
#include "system.h"
using namespace std;


int main(){
	//cout << "input simulation size" << endl;

	/*
	int N_size;
	try {
		cin >> N_size;
	} catch (...) {
		return 1;
	}
	cout << "input magnetic field(T)" << endl;
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
	cout << "input simulation cycle" << endl;
	int Cyc;
	try {
		cin >> Cyc;
	} catch (...) {
		return 1;
	}
	*/
	int N_size = 32;
	double temp = 300.0;
	int Cyc = 10000000;

	ofstream par_txt("par.txt");
	par_txt << "simulation_size " << N_size*N_size << endl;
	//par_txt << "magnetic_field " << H  << "T" << endl;
	par_txt << "Temperature " << temp << "K" << endl;
	par_txt << "simulation_cycle " << Cyc << endl;
	par_txt.close();

	//ofstream debug_data("debug.dat");
	//ofstream debug_system("system.dat");

	for(int h_i=0; h_i < 100; h_i++){

	}
	double H = 100.0;
	double h_eff = H*mu_avog;
	double J_interact = 0.0;

	objSystem simulation_system(H,J_interact,temp,N_size);

	vector<double> energy_step(Cyc,-1.0);
	for(int i = 0; i < Cyc; i++){
		simulation_system.gibbs_sampling();
		energy_step.at(i) = simulation_system.calculationEnergy();
	}

	double res_ave = 0.0;

	ofstream result("energy.dat");
	for(int i = 0; i < Cyc; i++){
		result << i << " " << energy_step.at(i) << endl;
		res_ave += energy_step.at(i);
	}

	res_ave /= static_cast<double>(Cyc);

	//debug_data << H << " " << res_ave << endl;

	result.close();

	//debug_data.close();
	//debug_system.close();

	return 0;
}
