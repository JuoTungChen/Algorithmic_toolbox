#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using std::vector;

int get_majority_element_countsort(vector<int> &a, int left, int right) {
  	if (left == right) return -1;
  	if (left + 1 == right) return a[left];
	int count[right];
	for(int i = 0; i<right; i++){
		count[i] = 0;
	} 
	for(int i = left; i<right; i++){
		count[a[i]] += 1;
		if (count[a[i]] > right/2)
			return count[a[i]];
	} 
//	if (*std::max_element(count, count+right) > (right/2))
//		return *std::max_element(count, count+right);
		//return std::max_element(count, count+right)- count;
  	return -1;
}

int count(vector<int> &a, int left, int right, int element){
	int count = 0;
	for(int i=left; i<=right; i++){
		if(a[i]==element){
			count++;
		}
	}
	return count;
}

int get_majority_element(vector<int> &a, int left, int right){
	int n = (right - left), k = floor((double)n/2);
	if(left == right) return -1;
	if(left + 1 == right) return a[left];
	int mid = floor((double)(right - left)/2) + left;
	int leftmaj = get_majority_element(a, left, mid);
	int rightmaj = get_majority_element(a, mid+1, right);
	if(leftmaj == rightmaj)	return leftmaj;
       	int lcount = count(a, left, right, leftmaj);
	int rcount = count(a, left, right, rightmaj);
	if (lcount >= k+1)
		return leftmaj;
	else if (rcount >= k+1)
		return rightmaj;
	else
		return -1;
}


int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size())!= -1) << '\n';
  //std::cout << "majority = "<< get_majority_element(a, 0, a.size())<< std::endl;
}
