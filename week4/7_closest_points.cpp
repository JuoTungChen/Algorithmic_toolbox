#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <cfloat>

using namespace std;
using std::vector;
using std::string;
using std::pair;
using std::make_pair;
using std::min;
using std::cout;
using std::endl;
bool ycmp(const pair<int, int> &x, const pair<int, int> &y){
	if(x.second != y.second)	return x.second < y.second;
	else	return x.first < y.first;
}

bool xcmp(const pair<int, int> &x, const pair<int, int> &y){
	if(x.first != y.first)	return x.first < y.first;
	else	return x.second < y.second;
}

double distance(pair<int ,int> & p1, pair<int, int> & p2){
	return sqrt((p1.first - p2.first) * (p1.first - p2.first) +
			(p1.second - p2.second) * (p1.second - p2.second));
}

double brute_force(vector<pair<int, int> > & p, int n){
	double dmin = 1e9; 
	for (int i = 0; i < n; i++){
		for (int j = i+1 ; j < n; j++){
			if(distance(p[i], p[j]) < dmin){
				dmin = distance(p[i], p[j]);
				//cout<<"dmin = "<<dmin<<endl;
			}
		}
	}
	return dmin;
}

double strip_closest(vector<pair<int, int> > & strip, double d){
	double dmin = d;
	sort(strip.begin(), strip.end(), ycmp);
	for (int i = 0; i < strip.size(); i++){
		for(int j = i+1; (j < strip.size()) && ((strip[j].second - strip[i].second) < d); j++){
		//for(int j = i+1; (j < n) || (j <= i+7) ; j++){
			if(distance(strip[i], strip[j]) < dmin)
				dmin = distance(strip[i], strip[j]);
		}
	}
	//cout << "dmin = "<< dmin <<endl;
	return dmin;
}

double recursive(vector<pair<int, int> > & s, int len){
	//int len = r-l;
	if (len <= 3 ){
		return brute_force(s, len);
	}
	else{
		int mid = floor(len / 2);
		
		vector<pair<int, int> > sl;
		vector<pair<int, int> > sr;

		for (int i = 0; i < len; i++){
			if (i < mid){
				sl.push_back(make_pair(s[i].first, s[i].second));
				//sl[i].first = s[i].first;
				//sl[i].second = s[i].second;
			}
			else{
				sr.push_back(make_pair(s[i].first, s[i].second));
				//sr[i].first = s[i].first;
				//sr[i].second = s[i].second;
			}
		} 

		//pair<int, int> midPoint = s[mid];
		double dl = recursive(sl, mid);
		double dr = recursive(sr, len - mid);
		double d = min(dl , dr);

		vector<pair<int ,int> > strip;
		//int strip_size = 0;
		for (int i = 0; i < len; i++){
			if(abs(s[i].first - s[mid].first) < d){
				strip.push_back(s[i]);
				//strip_size++;
			}
		}
		//std::cout << "d = "<< d <<std::endl;
		return min(d, strip_closest(strip, d));
	}	

}

double minimal_distance(vector<int> & x, vector<int> & y) {
  
	vector<pair<int, int> > points;
	int n = x.size();
	for(int i =0; i < n; i++){
		points.push_back(make_pair(x[i], y[i]));
	}
	if (n < 2)
		return 0.0;
	else if (n == 2)
		return distance(points[0], points[1]);
	else{
		sort(points.begin(), points.end(), xcmp);

		return recursive(points, n);
	}
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> x(n);
  vector<int> y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cout << std::fixed;
  std::cout << std::setprecision(9) << minimal_distance(x, y) << "\n";
}
