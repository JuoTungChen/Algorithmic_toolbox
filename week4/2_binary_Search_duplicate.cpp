#include <iostream>
#include <cassert>
#include <vector>
#include <math.h>
#include <string>

using std::vector;

int binary_search(const vector<int> &a, int x) {
  	int left = 0, right = (int)a.size(); 
	int index = -1; //record the position of the key
	while (left <= right){
		int mid = floor(left + (double)(right-left)/2);
		if (a[mid]==x) {
			index = mid;
			right = mid - 1;  //find if there is any duplicates less than the current position
		}
		else if (x < a[mid]){
			right = mid - 1;
		}
		else{ 
			left = mid + 1;
		}
	}
	if (index != -1) return index;  //found the key
	return -1;  //not found
}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    std::cout << binary_search(a, b[i]) << ' ';
  }
}
