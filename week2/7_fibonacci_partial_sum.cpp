#include <iostream>
#include <vector>
#include <string>
using std::vector;
using namespace std;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}
/*
long long get_fibonacci_partial_sum_fast(long long from, long long to) {
	long long sum = 0;
	long long n = (to+2) % 60;
	//long long S[n+1] ={};
	long long f0 = 0;
	long long f1 = 1;
	for (int i=2 ; i<=n; i++){
		//S[i] = (S[i-1]+S[i-2]) % 10;
		//std::cout << "S["<<i<<"] = "<< S[i]<<std::endl;
		long long f = (f0 + f1) % 10;
		f0 = f1;
		f1 = f;
	}
	if (from==to){
		sum = S[n]- S[n-1];
		//std::cout << "S[n] = "<< S[n]<<std::endl;
		//std::cout << "sum =" << sum <<std::endl;	
	}
	else if(from == 0)
		sum = S[n] - 1;
	else if(from<=1)
		sum = S[n] - S[from];
	else
		sum = S[n] - S[from+1];
	if(sum<0){
		sum = (sum + 10) % 10;
	}	
	return	sum;
	
}
*/
long long fib(long long n){
	long long f0 = 0;
	long long f1 = 1;
	
	long long rem = (n+2) % 60;
	if (n <=1)
		return n;
	else{
	
		if (rem == 0)
			return 0;

		for (long long i=2; i<=rem; i++){
			long long f = (f0 + f1) % 10;
			f0 = f1;
			f1 = f;
		}
	long long s = f1 -1;
	return s;	
	
	}

}

long long fib_sum(long long from, long long to){
	from = from % 60;
	to = from + (to-from) % 60;
	long long sum = 0;
	if (from == 0 && to == 0)
		return 0;
	else if (to <= 1)
		return fib(to);
	else if (from == 0)
		return fib(to);
	else 
		sum = (abs(10 + fib(to) - fib(from -1)) % 10);

	return sum;

}

int main() {
    long long from, to;
    std::cin >> from >> to;
    //long long ans = abs(fib(to) - fib(from - 1)) % 10;
    //std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
    //std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
    //cout << "f(from)= "<< fib(from-1) <<" ans = " << ans << endl;
    cout << fib_sum(from, to) << endl;
}
