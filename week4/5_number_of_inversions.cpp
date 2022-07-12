#include <iostream>
#include <vector>

using std::vector;
using namespace std;

long long merge(vector<int> &a, int left, int  mid, int right){
	
	int i, j, k;
	long long inv_num = 0;
	i = left;	//index of the left subarray
	j = mid;	//index of the right subarray
	k = 0;	//index of the resultant merged subarray
	vector<int> b(right - left + 1);
	while((i < mid) && (j <= right)){
	 	//if the element in left subarray is smaller than that in the right subarray
		if(a[i] <= a[j]){	
			b[k++] = a[i++];  //put the smaller element into the result array
		}
		else{	//all the remaining elements in left-subarray will be greater than a[j]
			b[k++] = a[j++];
			inv_num += (mid-i);//increase mid-i inversions
		}
	}
	//put the remaining elements of left subarray into b
	while (i < mid){	
		b[k++] = a[i++];
	}
	//put the remaining elements of right subarray into b
	while (j <= right){	
		b[k++] = a[j++];
	}
	//copy the merged subarray back to the original array a
	for(i = left, k = 0; i<= right; i++, k++){
		a[i]=b[k];
	}
	return inv_num; 
}

long long get_number_of_inversions(vector<int> &a, long long left, long long right) {
  long long number_of_inversions = 0;
  if (right > left){ 
  	int ave = (right + left) / 2;
  	number_of_inversions += get_number_of_inversions(a,left, ave);
  	number_of_inversions += get_number_of_inversions(a, ave + 1, right);
  	number_of_inversions += merge(a, left, ave + 1, right);
  }
  return number_of_inversions;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  std::cout << get_number_of_inversions(a, 0, n-1) << '\n';

  /*for (size_t i = 0; i < n; i++) {
  	cout<<a[i]<<' ';
  }
  */
}
