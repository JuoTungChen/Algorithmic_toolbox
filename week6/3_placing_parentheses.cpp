#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <climits>
#include <cmath>

using std::vector;
using std::string;
using std::max;
using std::min;

long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}

void MinAndMax(int i, int j, vector<vector<long long>> &m, vector<vector<long long>> &M, string op){
	long long min_num = LLONG_MAX;
	long long max_num = LLONG_MIN;
	for (int k = i; k < j; k++){
		long long a = eval(M[i][k], M[k+1][j], op[k]);
		long long b = eval(M[i][k], m[k+1][j], op[k]);
		long long c = eval(m[i][k], M[k+1][j], op[k]);
		long long d = eval(m[i][k], m[k+1][j], op[k]);
		min_num = min(min(min_num, min(a,b)), min(c,d));
		max_num = max(max(max_num, max(a,b)), max(c,d));
	}
	m[i][j] = min_num;
	M[i][j] = max_num;
}

long long get_maximum_value(const string &exp) {
	int n = (1+exp.size())/2;
	//std::cout<<"n = "<<n <<std::endl;

	vector<vector<long long>> m(n+1, vector<long long>(n+1));
	vector<vector<long long>> M(n+1, vector<long long>(n+1));
       	string op;
	for(int i = 0; i<n; i++){
		m[i][i] = (exp[2*i] - '0');
		M[i][i] = (exp[2*i] - '0');
		if(i<n-1)
			op+=exp[2*i+1];
	}
	

	//std::cout<<op<<std::endl;

	for(int s = 1; s<=(n-1); s++){
		for(int i = 0; i<(n-s); i++){
			int j = i+s;
			//std::cout<<"s = "<<s<<", i = "<<i<<", j = " <<j<<std::endl;
			MinAndMax(i, j, m, M, op);	
		}
	}
	/*
	for(int i = 0; i< n; i++){
		for(int j =0; j<n; j++)
			std::cout<<m[i][j]<<' ';
		std::cout<<std::endl;
	}
	std::cout<<std::endl;
	for(int i = 0; i< n; i++){
		for(int j =0; j<n; j++)
			std::cout<<M[i][j]<<' ';
		std::cout<<std::endl;
	}
	*/
	//return 0;
  	return M[0][n-1];
}

int main() {
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}
