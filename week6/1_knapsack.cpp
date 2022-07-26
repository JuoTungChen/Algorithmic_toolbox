#include <iostream>
#include <vector>

using std::vector;

int optimal_weight(int W, const vector<int> &w) {
	int n = w.size();     // n = number of items
	int table[W+1][n+1];  //construct a table to record the results
  	int current_weight = 0; //record the result
	for (int i = 0; i <= W; i++){
		for (int j = 0; j <= n; j++){
			table[i][0] = 0;
			table[0][j] = 0;	
		}
	}

	for (int i = 1; i <= n; i++){
		for(int k = 1; k <= W; k++){
			table[k][i] = table[k][i-1];
			if (w[i-1] <= k){
				current_weight = table[k-w[i-1]][i-1] + w[i-1];
				if (table[k][i] < current_weight)
					table[k][i] = current_weight;
			}
		}
	}
/*
  	for (size_t i = 0; i < w.size(); ++i) {
    		if (current_weight + w[i] <= W) {
      			current_weight += w[i];
    		}
  	}
*/
  	return table[W][n];
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
