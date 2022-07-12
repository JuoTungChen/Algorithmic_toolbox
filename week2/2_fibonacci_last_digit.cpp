#include <iostream>

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}

int get_fibonacci_last_digit_fast(int n){
	int F[n+1] = {};
	F[0] = 0;
	F[1] = 1;
	for (int i = 2 ; i <= n ; i++){
		F[i] = (F[i-1] + F[i-2]) % 10;
	}
	return F[n];
}


int main() {
    int n;
    std::cin >> n;
    //int c = get_fibonacci_last_digit_naive(n);
    //std::cout << c << '\n';

    //std::cin >> n;
    int r = get_fibonacci_last_digit_fast(n);
    std::cout << r << '\n';



}

