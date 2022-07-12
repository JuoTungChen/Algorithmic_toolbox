#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;

int partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}

void partition3(vector<int> &a, int l, int r, int &i, int &j){
	//if only two elements	
	if(r - l <= 1){
		if (a[r] < a[l])
			swap(a[r], a[l]);
		i = l;
		j = r;
		return;
	}
	
	int mid = l;
	int pivot = a[l];   //pivot
	while (mid <= r){
		if (a[mid] < pivot)
			swap(a[l++], a[mid++]);
		else if (a[mid] == pivot)
			mid++;
		else if (a[mid] > pivot)
			swap(a[mid], a[r--]);

	}
	i = l-1;
	j = mid;

}


void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);  //select random pivot
  swap(a[l], a[k]);
  int i, j;
  partition3(a, l, r, i, j);

  randomized_quick_sort(a, l, i);  //sort left part
  randomized_quick_sort(a, j, r);  //sort right part
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
