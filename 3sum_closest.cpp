#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int> &num, int target) {
		int diff = INT_MAX;
		sort(num.begin(), num.end());
		
		for (int left=0; left<num.size(); ++left) {
			int mid = left + 1;
			int right = num.size()-1;
			while (mid < right) {
				int sum = num[left] + num[mid] + num[right];
				if (abs(sum-target) < abs(diff)) diff = sum - target;
				if (sum > target) --right;
				else if (sum < target) ++mid;
				else return target;
			}
		}
		return target+diff;
	}
};

int main()
{
	vector<int> num;
/*
	num.push_back(1);
	num.push_back(1);
	num.push_back(1);
	num.push_back(1);
*/
	num.push_back(0);
	num.push_back(1);
	num.push_back(2);
	Solution s;
	cout << s.threeSumClosest(num, 0) << endl;
}
