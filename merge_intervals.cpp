#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

bool mysort(const Interval a, const Interval b) {
	return a.start < b.start;
}

class Solution {
public:
	vector<Interval> merge(vector<Interval> &intervals) {
		vector<Interval> result;
		if (intervals.size() == 0) return result;

		sort(intervals.begin(), intervals.end(), mysort);
		result.push_back(intervals[0]);		
		for (int i=1; i<intervals.size(); ++i) {
			vector<Interval>::iterator last = result.end();	
			--last;
			if (intervals[i].start > last->end) {
				result.push_back(intervals[i]);
			}
			else {
				last->end = max(intervals[i].end, last->end);
			}
		}
		return result;	
	}
};

int main()
{
	vector<Interval> intervals;
	intervals.push_back(Interval(1, 4));
	intervals.push_back(Interval(1, 5));

	Solution s;
	vector<Interval> res = s.merge(intervals);	
}
