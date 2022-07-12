#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;

long double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  	long double value = 0.0;
	if (capacity <= 0 || weights.empty())
		return 0;
	long double max = 0.0;
  	long d = 0;    	
        vector<long double> ratio(values.size());	
	for (long i = 0; i < ratio.size(); i++){		
		ratio[i] = (long double) values[i]/weights[i];
		if (max < ratio[i] && weights[i] > 0){
			max = ratio[i];
			d = i;
		}
	}

	/*
	vector<int>::iterator m;
	m = max_element(values.begin(), values.end());	//the pointer to the most expensive item
	int index = m - values.begin();  //the index of m
   
	double amount = std::min(weights[index], capacity);
	value = *m * amount / weights[index];
	weights.erase(weights.begin()+index);
	values.erase(m);
  	return value + get_optimal_value(capacity-weights[index], weights, values);
	*/

	long double amount = std::min(weights[d], capacity);
	value = values[d] * amount / (long double) weights[d];
	//std::cout<<weights[d]<<std::endl;
	//weights[d] -= amount;
	//capacity -= amount;
	weights.erase(weights.begin()+d);
	values.erase(values.begin()+d);
  	return value + get_optimal_value(capacity - amount, weights, values);
    

}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  long double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
