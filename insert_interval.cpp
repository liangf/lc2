#include <iostream>
#include <vector>
using namespace std;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};
/*
// this method cannot ac, erasing is much consuming time.
class Solution {
public:
	vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
		vector<Interval>::iterator it = intervals.begin();
		while (it != intervals.end()) {
			if(newInterval.start > it->end) ++it;
			else if (newInterval.end < it->start) {
				it = intervals.insert(it, newInterval);
				return intervals;
			}
			else {
				newInterval.start = min(newInterval.start, it->start);
				newInterval.end = max(newInterval.end, it->end);
				it = intervals.erase(it);
			}
		}	
		intervals.push_back(newInterval);
		return intervals;
	}
};
*/

class Solution {
public:
	vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
		vector<Interval> result;
		vector<Interval>::iterator it = intervals.begin();
		while (it != intervals.end()) {
			if (newInterval.start > it->end) {
				result.push_back(*it);
			}
			else if(newInterval.end < it->start) {
				result.push_back(newInterval);
				newInterval = *it;
			}
			else {
				newInterval.start = min(newInterval.start, it->start);
				newInterval.end = max(newInterval.end, it->end);
			}
			++it;
		}
		result.push_back(newInterval);
		return result;
	}
};

int main()
{
	vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);

	vec.insert(vec.begin(), 0);
	for (int i=0; i<vec.size(); ++i) {
		cout << vec[i] << " ";
	}
	cout << endl;
}
