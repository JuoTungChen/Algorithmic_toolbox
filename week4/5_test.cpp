#include <iostream>
#include <vector>
#include <string>
using std::vector;
using namespace std;

/*long long merge(vector<int> &a, vector<int> &b, long long left, long long mid, long long right);
long long get_number_of_inversions(vector<int> &a, vector<int> &b, long long left, long long right) {
  long long number_of_inversions = 0, ave = 0;
  if (right > left){ 
  	long long ave = (right + left) / 2;
	cout<<"mid = "<<ave<<endl;
  	number_of_inversions += get_number_of_inversions(a, b, left, ave);
  	number_of_inversions += get_number_of_inversions(a, b, ++ave, right);
  	number_of_inversions += merge(a, b, left, ++ave, right);
  }
  return number_of_inversions;
}

long long merge(vector<int> &a, vector<int> &b, long long left, long long mid, long long right){
	
	long long i, j, k;
	long long inv_num = 0;
	i = left;	//index of the left subarray
	j = mid;	//index of the right subarray
	k = left;	//index of the resultant merged subarray
	while((i <= mid) && (j <= right)){
		cout<<"loop"<<endl;
	 	//if the element in left subarray is smaller than that in the right subarray
		if(a[i] <= a[j]){	
			cout<<"a[i] = "<<a[i]<<" a[j] = "<<a[j]<<" j = "<<j<<endl;
			b[k++] = a[i++];  //put the smaller element into the result array
		}
		 //if the element in left subarray is bigger than that in the right subarray
		else{	//all the remaining elements in left-subarray will be greater than a[j]
			b[k++] = a[j++];
			inv_num += (mid-i);//increase mid-i inversions
			cout<<"mid = "<<mid<<"i = "<<i<<"inv = "<<inv_num<<endl;
		}
	}
	//put the remaining elements of left subarray into b
	while (i <= mid-1){	
		b[k++] = a[i++];
	}
	//put the remaining elements of right subarray into b
	while (j <= right){	
		b[k++] = a[j++];
	}
	//copy the merged subarray back to the original array a
	for(i = left; i<= right; i++)
		a[i]=b[i];
	//cout<<"inv = "<<inv_num<<endl;
	return inv_num; 
	//return 0;
}

*/

/*
int merge(int data[], int l, int mid, int r){

	long long inv = 0;
	int n1 = mid - l + 1;
	int n2 = r - mid;
	cout<<"l = "<<l<<", r = "<<r<<", n1 = "<<n1<<", n2 = "<<n2<<endl;
	int a[n1], b[n2] ;
	for(int i = 0; i< n1; i++){
		a[i] = data[l+i];
	}
	for (int i = 0; i < n2; i++){
		b[i] = data[mid+i+1];
	}
	cout << "data = ";
	for(int i = 0; i < r; i++){
		cout<<data[i]<<' ';
	}	
	cout<<endl;
	int i = 0, j = 0, k = l;
	while ((i <= n1) && (j<=n2)){
		if(a[i] <= b[j]){
			data[k] = a[i];
			i++;
		}
		else{
			data[k] = b[j];
			j++;
			inv += (n1 - i);
		}
		cout<<data[k]<<' ';
		k++;
	}
	cout<<endl;
	while (i< n1){
		data[k] = a[i];
		k++;i++;
	}
	while (j < n2){
		data[k] = b[j];
		k++; j++;
	}


	return inv;
}
*/
long long merge(long long arr[], int left, int mid, int right) {
  int i = left, j = mid, k = 0;
  long long invCount = 0;
  int temp[(right - left + 1)];
 
  while ((i < mid) && (j <= right)) {
    if (arr[i] <= arr[j]) {
      temp[k] = arr[i];
      ++k;
      ++i;
    } else {
      temp[k] = arr[j];
      invCount += (mid - i);
      ++k;
      ++j;
    }
  }
 
  while (i < mid) {
    temp[k] = arr[i];
    ++k;
    ++i;
  }
 
  while (j <= right) {
    temp[k] = arr[j];
    ++k;
    ++j;
  }
 
  for (i = left, k = 0; i <= right; i++, k++) {
    arr[i] = temp[k];
  }
 
  return invCount;
}
long long mergeSort(long long arr[], int left, int right) {
  long long invCount = 0;
 
  if (right > left) {
    int mid = (right + left) / 2;
    invCount = mergeSort(arr, left, mid);
    invCount += mergeSort(arr, mid + 1, right);
    invCount += merge(arr, left, mid + 1, right);
  }
  return invCount;
}
 
long long getInversions(long long arr[], int n) {
  return mergeSort(arr, 0, n - 1);
}

/*
long long merge_sort(int data[], int low, int high){
	long long inv_count = 0;
	if(high > low){
		int mid = (low + high) / 2;
		inv_count += merge_sort(data, low, mid);
		inv_count += merge_sort(data, mid+1, high);
		inv_count += merge(data, low, mid, high);
	}
	return inv_count;
}

*/

int main() {
  int n;
  std::cin >> n;
  //vector<int> a(n);
	long long a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  //vector<int> b(n);
  cout << getInversions(a, n) << '\n';
	cout<<"result array = ";
  for (size_t i = 0; i < n; i++) {
  	cout<<a[i]<<' ';
  }
}
