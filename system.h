#include <vector>
#include "spin.h"
#include "PBC.h"
using namespace std;

class objSystem{
	public:
		int systemSize;
		double interactionJ;
		double magneticH;
		vector<vector<SpinStruct>> spinsArray;
		double calculationEnergy();
};
