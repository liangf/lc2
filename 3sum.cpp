#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
class Solution {
public:
	vector<vector<int> > threeSum(vector<int> &num) {
		vector<int> three(3, -1);
		vector<vector<int> > result;
		sort(num.begin(), num.end());
		int left=0, right=num.size()-1;

		while (left < right) {
			int mid = left + 1;
			while (mid < right) {
				int sum = num[left] + num[mid] + num[right];
				if (sum > 0) --right;
				else if (sum < 0) ++mid;
				else {
					three[0] = num[left];
					three[1] = num[mid];
					three[2] = num[right];
					result.push_back(three);
					while (mid+1<=right && num[mid]==num[mid+1]) ++mid;
					++mid;
					while (right-1>=mid && num[right]==num[right-1]) --right;
					--right;
				}
			}
			while (left+1<num.size() && num[left]==num[left+1]) ++left;
			++left;
		}
		return result;
	}
};
*/

class Solution {
public:
	vector<vector<int> > threeSum(vector<int> &num) {
		vector<int> three(3, -1);
		vector<vector<int> > result;
		sort(num.begin(), num.end());
		
		for (int left=0; left<num.size(); ++left) {
			int mid = left + 1;
			int right = num.size()-1;
			while (mid < right) {
				int sum = num[left] + num[mid] + num[right];
				if (sum > 0) --right;
				else if (sum < 0) ++mid;
				else {
					three[0] = num[left];
					three[1] = num[mid];
					three[2] = num[right];
					result.push_back(three);
					while (mid+1<=right && num[mid]==num[mid+1]) ++mid;
					++mid;
					while (right-1>=mid && num[right]==num[right-1]) --right;
					--right;
				}
			}
			while (left+1<num.size() && num[left]==num[left+1]) ++left;
		}
		return result;
	}
};

int main()
{
	vector<int> num;
/*
	num.push_back(-1);
	num.push_back(0);
	num.push_back(1);
	num.push_back(2);
	num.push_back(-1);
	num.push_back(-4);
	num.push_back(-1);
	num.push_back(-1);
*/
	num.push_back(1);
	num.push_back(2);
	num.push_back(-2);
	num.push_back(-1);
	Solution s;
	vector<vector<int> > res = s.threeSum(num);
	for (int i=0; i<res.size(); ++i) {
		for (int j=0; j<res[i].size(); ++j) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
}
