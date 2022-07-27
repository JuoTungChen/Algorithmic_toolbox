#include <iostream>
#include <vector>

using std::vector;

int optimal_weight(int W, const vector<int> &w) {
	int n = w.size();     // n = number of items

	//2D array will cause unknown signal 11 -> use 2D vector instead
	vector<vector<int>> table(W+1, vector<int>(n+1));
	int result_weight = 0; //record the result
		
	for (int i = 0; i <= n; i++){
		for(int k = 0; k <= W; k++){
			if(i == 0 || k == 0)
				table[k][i] = 0;

			else if (w[i-1] <= k)
				table[k][i] = std::max(table[k-w[i-1]][i-1]+w[i-1], table[k][i-1]);
			else
				table[k][i] = table[k][i-1];

			}
		}
	
	
	result_weight = table[W][n];
	return result_weight;
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
