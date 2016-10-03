#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

bool mysort(const pair<int, int> a, const pair<int, int> b)
{
	return a.first < b.first;
}
/*
class Solution {
public:
	vector<int> twoSum(vector<int> &numbers, int target) {
		vector<int> result(2, -1);
		vector<pair<int, int> > nums;
		for (int i=0; i<numbers.size(); ++i) {
			nums.push_back(make_pair(numbers[i], i+1));
		}
		sort(nums.begin(), nums.end(), mysort);
		int left=0, right=nums.size()-1;
		while (left < right) {
			int sum = nums[left].first + nums[right].first;
			if (sum > target) --right;
			else if (sum < target) ++left;
			else {
				if (nums[left].second < nums[right].second) {
					result[0] = nums[left].second;
					result[1] = nums[right].second;
				}	
				else {
					result[0] = nums[right].second;
					result[1] = nums[left].second;
				}
				return result;
			}
		}
		return result;	
	}
};
*/

class Solution {
public:
	vector<int> twoSum(vector<int> &numbers, int target) {
		vector<int> result(2, -1);
		unordered_map<int, int> umap;
		
		for (int i=0; i<numbers.size(); ++i) {
			if (umap.find(target-numbers[i]) != umap.end()) {
				int j = umap[target-numbers[i]];
				result[0] = i<j ? i+1 : j+1;
				result[1] = i<j ? j+1 : i+1;
				return result;
			}
			else umap[ numbers[i] ] = i;
		}	
		return result;
	}
};

int main()
{
	vector<int> numbers;
	numbers.push_back(2);
	numbers.push_back(7);
	numbers.push_back(11);
	numbers.push_back(15);

	Solution s;
	vector<int> res = s.twoSum(numbers, 9);
	cout << res[0] << " " << res[1] << endl;
}
