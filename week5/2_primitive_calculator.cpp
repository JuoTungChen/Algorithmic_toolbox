#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using std::vector;

vector<int> optimal_sequence(int n) {
  vector<int> sequence;
  while (n >= 1) {
    sequence.push_back(n);
    if (n % 3 == 0) {
      n /= 3;
    } else if (n % 2 == 0) {
      n /= 2;
    } else {
      n = n - 1;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

vector<int> optimal_sequence_dp(int n, vector<int> &s){
	vector<int> sequence;
	vector<int> p(n+1);  //record the predecessors with min steps
	p.push_back(0);   //p[0] = 0
	//base condition
	if(n <= 1){
		s[1] = 0;
		p[1] = 1;
		sequence.push_back(p[1]);	
	}
	else{
		for(int i = 2; i<=n ; i++){
			s[i] = s[i-1] + 1;    //assume min step is from the former num
			p[i] = i-1;		      
			if(i % 2 == 0){	      //check if i can be divided by 2
				if(s[i/2] < s[i]){
					s[i] = s[i/2]+1;    //set min step to be the min of steps coming from i-1 or i/3
					p[i] = i/2;	//set predecessor to be i/2
				}
			}		
			if(i % 3 == 0){       //check if i can be divided by 3
				if(s[i/3] < s[i]){
					s[i] =s[i/3]+1;    //set min step to be the min of steps coming from i-1 or i/3
					p[i] = i/3;     //set predecessor to be i/3
				}
			}
		}
		//reconstruct the path	
		for(int i = n; i!=0; i = p[i]){
			sequence.push_back(i);
		}
		reverse(sequence.begin(), sequence.end());
	}
	return sequence;
}


int main() {
  	int n;
  	std::cin >> n;
	vector<int> s(n+1);  //record the min steps for each num
	s.push_back(0);   //s[0] = 0
  	vector<int> sequence = optimal_sequence_dp(n, s);
  	std::cout << s[n] << std::endl;
  	for (size_t i = 0; i < sequence.size(); ++i) {
    		std::cout << sequence[i] << " ";
  	}
}
