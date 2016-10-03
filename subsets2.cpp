#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution {
public:
	vector<vector<int> > subsetsWithDup(vector<int> &S) {
		sort(S.begin(), S.end());
		vector<vector<int> > solution;
		vector<int> result;
		for (int len=0; len<=S.size(); ++len) {
			dfs(S, 0, len, result, solution);
		}
		return solution;
	}
	void dfs(vector<int> &s, int start, int len, vector<int> &result,
				vector<vector<int> > &solution) {
		if (result.size() == len) {
			solution.push_back(result);
			return;
		}
		unordered_set<int> uset;
		for (int i=start; i<s.size(); ++i) {
			if (uset.find(s[i]) == uset.end()) {
				uset.insert(s[i]);
				result.push_back(s[i]);
				dfs(s, i+1, len, result, solution);
				result.pop_back();
			}
		}
	}
};

int main()
{
	vector<int> S;
	S.push_back(2);
	S.push_back(2);
	S.push_back(1);

	Solution s;
	vector<vector<int> > sol = s.subsetsWithDup(S);
	for (int i=0; i<sol.size(); ++i) {
		for (int j=0; j<sol[i].size(); ++j) {
			cout << sol[i][j] << " ";
		}
		cout << endl;
	}
}
