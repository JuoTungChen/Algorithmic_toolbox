#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::swap;

class Seg{
	public:
		long long value;
		int type;    //left=0, point=1, right=2
		int id;
};

bool cmp(const int &x, const int &y){
	return x < y;
}
/*
vector<int> fast_count_segments(vector<int> starts, vector<int> ends, vector<int> points, int m) {

  	vector<int> cnt(m);    //result
	sort(starts.begin(), starts.end(), cmp);
	sort(ends.begin(), ends.end(), cmp);
	//sort(points.begin(), points.end(), cmp);
	int seg_len = starts.size();
	int j = 0;
	int k = 0;
	int count = 0;
	for (int i = 0; i < m; i++){
		while ((j < seg_len) && (starts[j] <= points[i])){
			j += 1;
			count += 1;
		}
		while ((k < seg_len) && (ends[k] < points[i])){
			k += 1;
			count -= 1;		
		}
		cnt[i] = count;
	}

	for(int i = 0; i<points.size(); i++){
		std::cout<<points[i]<<' ';
	}
	std::cout<<std::endl;
	return cnt;
}
*/
vector<int> fast_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  	vector<int> cnt(points.size());    //result
	int n = starts.size() + ends.size() + points.size();
	int count = 0;
	vector<Seg> all(n);
	for(int i = 0; i < starts.size(); i++){
		all[count++] = {.value= starts[i], .type= 0, .id= -1};
		all[count++] = {.value= ends[i], .type= 2, .id= -1};
	}
	for (int i = 0; i < points.size(); i++){
		all[count++] = {.value= points[i], .type= 1, .id= i};
		cnt[i] = 0;
	}

	sort(all.begin(), all.end(), [](const Seg &x, const Seg &y){
			if (x.value != y.value)	return x.value < y.value;
			else return x.type < y.type;
			});
	int c = 0;
	for(int i = 0; i < count; i++){
		if (all[i].type == 0)	c++;
		else if (all[i].type == 2) c--;
		else if (all[i].type == 1) cnt[all[i].id] = c;
	}
  	return cnt;
}

vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  for (size_t i = 0; i < points.size(); i++) {
    for (size_t j = 0; j < starts.size(); j++) {
      cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
    }
  }
  return cnt;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<int> starts(n), ends(n);
  for (size_t i = 0; i < starts.size(); i++) {
    std::cin >> starts[i] >> ends[i];
  }
  vector<int> points(m);
  for (size_t i = 0; i < points.size(); i++) {
    std::cin >> points[i];
  }
  //use fast_count_segments
  vector<int> cnt = fast_count_segments(starts, ends, points);
  for (size_t i = 0; i < cnt.size(); i++) {
    std::cout << cnt[i] << ' ';
  }
}
