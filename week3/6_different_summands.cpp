#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  for(int k = n, i = 1; k > 0; i++){
 	 		
	if ( k <= 2*i ){
		summands.push_back(k);
		k-=k;
	}
	
	else{  
		summands.push_back(i);
		k=k-i;
	}
  }
  	return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
