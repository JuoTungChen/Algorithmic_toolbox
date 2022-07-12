#include <iostream>

int get_change(int m) {
  return ((m/10) + (m % 10)/5 + (m % 5));
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
