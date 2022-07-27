#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using std::vector;

int lcs2(vector<int> &a, vector<int> &b, int n, int m) {
	
	int dp[n+1][m+1];
	for(int i = 0; i<=n; i++)
		for (int j = 0; j<=m; j++)
			dp[i][j] = 0;

	for(int i = 0; i<=n; i++){
		for (int j = 0; j<=m; j++){
			if(i == 0 || j == 0)
				dp[i][j] = 0;	

			else if(a[i-1] == b[j-1])
				dp[i][j] = 1 + dp[i-1][j-1];
		
			else
  				dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
		}	
	}
	return dp[n][m];
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }
//	vector<vector<int>> dp(m+1, vector<int>(n+1, -1));  //create dp table for (0~n)x(0~m)

//	for(int i = 0; i<=n; i++)
//		for (int j = 0; j<=m; j++)
//			dp[i][j] = -1;

  std::cout << lcs2(a, b, n, m) << std::endl;
}
