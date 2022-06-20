#include <iostream>

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

long long gcd(int a, int b){
	if (b == 0){
		return a;
	} 
	int a_remain = a % b;
	return gcd(b, a_remain);
}
long long lcm(int a, int b){
	return (long long) a*b / gcd(a,b);

}


int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm(a, b) << std::endl;
  return 0;
}
