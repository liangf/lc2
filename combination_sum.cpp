#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
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

		for (int i=start; i<candidates.size(); ++i) {
			result.push_back(candidates[i]);
			dfs(candidates, target-candidates[i], result, solution, i);
			result.pop_back();
		}
	}
};

int main()
{
	vector<int> candidates;
	candidates.push_back(2);
	candidates.push_back(3);
	candidates.push_back(6);
	candidates.push_back(7);

	Solution s;
	vector<vector<int> > sol = s.combinationSum(candidates, 7);
	for (int i=0; i<sol.size(); ++i) {
		for (int j=0; j<sol[i].size(); ++j) {
			cout << sol[i][j] << " ";
		}
		cout << endl;
	}
}
