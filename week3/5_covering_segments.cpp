#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
  int start, end;
};

vector<int> optimal_points(vector<Segment> &segments) {
  	sort(segments.begin(), segments.end(), [](const Segment &x, const Segment &y){
				//compare the end points in segment
				if (x.end != y.end){
					return x.end < y.end;
				}
				//compare the start points if end points are equal
				return x.start < y.start;
			});
	vector<int> points;
	// let the smallest end point be the first intersecting point
	int p = segments[0].end;
	points.push_back(p);

  	for (size_t i = 0; i < segments.size(); ++i) {
    		if((p<segments[i].start) || (p > segments[i].end)){
			p = segments[i].end;  //update p to the next end point
			points.push_back(p);  //store p into the vector
		}	
  	}
  	return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  // output number of intersecting points
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
