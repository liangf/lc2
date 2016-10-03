#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution {
public:
	vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
		vector<int> result;
		vector<vector<int> > solution;
		sort(candidates.begin(), candidates.end());
		dfs(candidates, target, result, solution, 0);
		return solution;
	} 
	void dfs(vector<int> &candidates, int target, vector<int> &result, 
				vector<vector<int> > &solution, int start) {
		if (target < 0) return;
		if (target == 0) {
			solution.push_back(result);
			return;
		}

		unordered_set<int> uset;
		for (int i=start; i<candidates.size(); ++i) {
			if (uset.find(candidates[i]) == uset.end()) {
				uset.insert(candidates[i]);
				result.push_back(candidates[i]);
				dfs(candidates, target-candidates[i], result, solution, i+1);
				result.pop_back();
			}
		}
	}
};

int main()
{
	vector<int> candidates;
	candidates.push_back(10);
	candidates.push_back(1);
	candidates.push_back(2);
	candidates.push_back(7);
	candidates.push_back(6);
	candidates.push_back(1);
	candidates.push_back(5);

	Solution s;
	vector<vector<int> > sol = s.combinationSum2(candidates, 8);
	for (int i=0; i<sol.size(); ++i) {
		for (int j=0; j<sol[i].size(); ++j) {
			cout << sol[i][j] << " ";
		}
		cout << endl;
	}
}
