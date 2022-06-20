#include <iostream>

int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
    }

    return sum % 10;
}

long long fib_sum_square(long long n){

	if (n <= 1)
		return n;

	long long f0 = 0;
	long long f1 = 1;
	n = n % 60;
	for (long long i = 2; i <= n+1; i++){
		long long f = (f0 + f1) % 10;
		f0 = f1;
		f1 = f;
	}
	long long sum = f1 * f0;
	return sum % 10;

}


int main() {
    long long n = 0;
    std::cin >> n;
    //std::cout << fibonacci_sum_squares_naive(n)<<std::endl;
    std::cout << fib_sum_square(n)<<std::endl;
}
