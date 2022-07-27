#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using std::vector;

int partition3(vector<int> &A) {
	int n = A.size();
	int sum = std::accumulate(A.begin(), A.end(), 0);
	//check if the sum can be divided into 3 parts
	if (sum % 3 != 0){
		return 0;
	}
	else if(sum % 3 == 0){
		int s = sum/3;
		vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(sum+1, vector<int>(sum+1)));

	  	dp[0][0][0] = true;
		for(int i = 0; i<=n; i++)
			dp[i][0][0] = true;    //set i axis 

		for (int i = 1; i<=n; i++){
			for (int j = 0 ; j<=sum; j++){
				for (int k = 0; k<=sum; k++){
					dp[i][j][k] = dp[i-1][j][k];
					if(j >= A[i-1] && dp[i-1][j-A[i-1]][k]) 		
						dp[i][j][k] = true;
					else if (k >= A[i-1] && dp[i-1][j][k-A[i-1]])
						dp[i][j][k] = true;	
			
				}
			}
		}

		if (dp[n][s][s]) return 1;	
		else return 0;
	}
	return 0;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> A(n);
  for (size_t i = 0; i < A.size(); ++i) {
    std::cin >> A[i];
  }
  std::cout << partition3(A) << '\n';
}
