#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;


bool IsGreaterOrEqual(string a, string b){
	std::stringstream x, y;
	string ab, ba;
	ab = a+b;
	ba = b+a;
	int a_num, b_num;
	x << ab;
	y << ba;
	x >> a_num;
	y >> b_num;
	//std::cout<<a_num<<", "<<b_num<<std::endl;
	if(a_num >= b_num)
		return true;
	else
		return false;
	x.str("");
	y.str("");
	x.clear();
	y.clear();
}


string largest_number(vector<string> a) {
  //write your code here
  	std::stringstream ret;
	string result;
	while(!a.empty()){
  		string max_digit = "0"; 
		int index = 0;
  		for (size_t i = 0; i < a.size(); i++) {
			if(IsGreaterOrEqual(a[i], max_digit)){
    				max_digit = a[i];
				index = i;
			}
  		}
		//std::cout<<"max_digit = "<<max_digit<<std::endl;	
		ret << max_digit;
		
		a.erase(a.begin()+index);
  		//convert string to num
    		result.append(ret.str());
  		ret.str("");
		ret.clear();
 	}
  	return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
