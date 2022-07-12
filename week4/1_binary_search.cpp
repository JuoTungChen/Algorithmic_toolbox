#include <iostream>
#include <cassert>
#include <vector>
#include <math.h>

using std::vector;

// int binary_search(const vector<int> &a, int x) {
//   	int left = 0, right = (int)a.size(); 
	
// 	while (left <= right){
// 		int mid = (right+left)/2;
// 		if (a[mid] > x) right = mid - 1;
// 	  else if (a[mid] < x) left = mid + 1;	
// 		else if (a[mid] == x) return mid;
// 	}
// 	return -1;

// }


int binary_search(const vector<int> & arr, int p, int r, int num) {
   if (p <= r) {
      int mid = (p + r)/2;
      if (arr[mid] == num)
         return mid ;
      if (arr[mid] > num)
         return binary_search(arr, p, mid-1, num);
      if (arr[mid] < num)
         return binary_search(arr, mid+1, r, num);
   }
   return -1;
}

/*
int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}
*/

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
    //std::cout << linear_search(a, b[i]) << ' ';

    std::cout << binary_search(a, 0, a.size()-1, b[i]) << ' ';
  }
}
