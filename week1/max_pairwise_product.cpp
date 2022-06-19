#include <iostream>
#include <vector>
#include <algorithm>

int MaxPairwiseProduct(const std::vector<int>& numbers) {
    int max_product = 0;
    int n = numbers.size();

    for (int first = 0; first < n; ++first) {
        for (int second = first + 1; second < n; ++second) {
            max_product = std::max(max_product,
                numbers[first] * numbers[second]);
        }
    }

    return max_product;
}

long long MaxPairwiseProductFast(std::vector<int> numbers) {
	int max_num1 = 0;
	int max_num2 = 0;
	long long max_product = 0;
	int n = numbers.size();
	sort(numbers.begin(), numbers.end());
	max_num1 = numbers.back(); 
        numbers.pop_back();	
	max_num2 = numbers.back();
	//std::cout << max_num1 << ' ' << max_num2 <<"\n"; 
	max_product = ((long long) max_num1) * max_num2;
	return max_product;
}


int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProductFast(numbers) << "\n";

    //std::cout << MaxPairwiseProduct(numbers) << "\n";
    return 0;
}
