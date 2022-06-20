#include <iostream>

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }
    std::cout<<sum<<std::endl;
    return sum % 10;
}

long long pisano(long long m){
	long long prev = 0;
	long long curr = 1;
	long long res = 0;
	for (long long i = 0 ; i< m*m; i++){
		long long temp = 0;
		temp = curr;
		curr = (prev+curr) % m;
		prev = temp;
		if(prev == 0 && curr == 1)
			res = i+1;
	}
	return res;
}



int fibonacci_sum_fast(long long n){
	if (n<=1)
		return n;
	n = (n+2) % 60;   //pisano period for 10 is 60
	int S[n+1] = {};
	S[0] = 0;
	S[1] = 1;
	int res = 1;
	for (int i = 2; i<=n ; i++){
		S[i] = (S[i-1] + S[i-2]) % 10;
	}
	if (S[n]==0)
		return 9;
	return (S[n]%10-1);
}

int main() {
    long long n = 0;
    std::cin >> n;
    //std::cout << fibonacci_sum_naive(n)<<'\n';
    std::cout << fibonacci_sum_fast(n)<<'\n';
}
