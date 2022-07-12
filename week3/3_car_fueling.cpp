#include <iostream>
#include <vector>
#include <string>
using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
	int location = 0;
	int refill = 0;
	int full_tank=tank;
	stops.push_back(dist);
	while (!stops.empty() && ((stops.front()-location) <= tank)){

		// no need to refill
		if ((location + tank) >= dist)
			return refill;
		//can't reach next stop
		if ((stops.front() - location) > tank)
			return -1;
		
		// if car cannot reach next stop without refilling
		if (stops.size()>1){
			if (((location + tank) >= stops.front()) && ((location + tank) - stops.at(1) < 0)){
				refill++;  //refill
				tank = full_tank;
			}
			else
				tank = tank - (stops.front()-location);
		}
		location = stops.front();     //update the current location
		//cout<<"location = "<<location<<" tank = "<<tank<<" refill = "<<refill<<std::endl;
		stops.erase(stops.begin());   //pop stops[0]

	}
	//cout<<"location = "<<location<<std::endl;
	
	if ((location + tank) < dist) 
    		return -1;
	return refill;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
