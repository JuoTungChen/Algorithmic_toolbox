#include <iostream>
#include <string>
#include <algorithm>

using std::string;
using namespace std;

int min(int x, int y, int z){
	return min(min(x, y), z);
}

int edit_distance(const string &str1, const string &str2) {

	int n = str1.length();
	int m = str2.length();
	int dp[n+1][m+1];      //create dp table (0~n)x(0~m)

	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= m; j++){
			if(i==0)              //set first row
				dp[i][j] = j;
			
			else if(j==0)         //set first column
				dp[i][j] = i;

			else if(str1[i-1] == str2[j-1])    //if last characters match
				dp[i][j] = min(dp[i][j-1]+1, dp[i-1][j]+1, dp[i-1][j-1]);

			else      //if last characters don't match -> set dp to the min of insert, delete, and mismatch
				dp[i][j] = 1+ min(dp[i][j-1], dp[i-1][j], dp[i-1][j-1]);
		}
	}

  	return dp[n][m];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
