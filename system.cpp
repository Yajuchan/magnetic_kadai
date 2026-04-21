#include "system.h"
using namespace std;

double objSystem::calculationEnergy(){
	double J = this->interactionJ;
	double h = this->magneticH;
	int N = this->systemSize;
	double E = -99.0;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			int sig_i = this->spinsArray.at(i).at(j).spinVector;
			int ip = PBC_set(N,i+1);
			int jp = PBC_set(N,j+1);
			int sig_j = this->spinsArray.at(ip).at(jp).spinVector;

		}
	}
	return E;
}
