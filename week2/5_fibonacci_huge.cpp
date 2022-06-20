#include <iostream>
#include <string>

using namespace std;

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }
    //std::cout <<"naive ="<< current <<'\n';
    return current % m;
}

long long pisano(long long m){
	long long prev = 0;
	long long curr = 1;
	long long res = 0;
	for (long long i = 0; i< m*m ; i++){
		
		long long temp = 0;
		temp = curr;
		curr = (prev + curr) % m;
		prev = temp;
		if (prev == 0 && curr == 1)
			res = i+1;
	}
	//cout << "pisano = "<< res <<endl;
	return res;

}

long long fibonacciModulo(long long n, long long m){
	n = n % pisano(m);
	long long prev = 0;
	long long curr = 1;
	if (n <= 1)
		return n;
	for (long long i = 0; i< n-1; i++){
		long long temp = 0;
		temp = curr;
		curr = (prev + curr) % m;
		prev = temp;
	
	}
	return curr % m;
}


long long fibonacci(long long n, long long m){
	long long F[n+1] = {};
	F[0] = 0;
	F[1] = 1;
	for (long long i = 2; i <= n ; i++)
		F[i] = (F[i-1] + F[i-2]) % m;

	//std::cout <<"fast ="<< F[n] <<'\n';

	return F[n];
}

long long get_fibonacci_huge_fast(long long n, long long m) {
	if (n <= 1)
		return n;
	if (m == 2)
		return (fibonacci(n,m)%3);
	else if (m == 3)
		return (fibonacci(n,m)%8);
	else if (m % 2 == 0 && m>=4) 
		return (fibonacci(n,m) % (4*n));
	else if (m % 2 == 1 && m>=5)
		return (fibonacci(n,m) % (8*n+4));	
	return 0;
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    //std::cout << get_fibonacci_huge_naive(n, m) << '\n';
    //std::cout << get_fibonacci_huge_fast(n, m) << '\n';
    cout << fibonacciModulo(n, m) << endl;



}
