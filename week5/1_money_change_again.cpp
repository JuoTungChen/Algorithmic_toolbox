#include <iostream>
#include <vector>
using namespace std;


int get_change(int m) {
	vector<int> minCoins(m+1);
	vector<int> coins;
	coins.push_back(1);
	coins.push_back(3);
	coins.push_back(4);
	minCoins[0] = 0;
	for(int i = 1; i <= m; i++){
		minCoins[i] = INT32_MAX; 
		for(int j = 0; j < coins.size(); j++){
			if(i >= coins[j]){
				int NumCoins = minCoins[i - coins[j]] + 1;
				if(NumCoins < minCoins[i])
					minCoins[i] = NumCoins;
			}
		}
	}
  	return minCoins[m];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
