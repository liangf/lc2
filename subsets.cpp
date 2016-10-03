#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int> > subsets(vector<int> &s) {
		sort(s.begin(), s.end());
		vector<vector<int> > solution;
		vector<int> result;
		for (int len=0; len<=s.size(); ++len) {
			dfs(s, 0, len, result, solution);
		}
		return solution;
	}
	void dfs(vector<int> &s, int start, int len, vector<int> &result,
				vector<vector<int> > &solution) {
		if (result.size() == len) {
			solution.push_back(result);
			return;
		}

		for (int i=start; i<s.size(); ++i) {
			result.push_back(s[i]);
			dfs(s, i+1, len, result, solution);
			result.pop_back();
		}
	}
};

int main()
{
	vector<int> S;
	S.push_back(1);
	S.push_back(2);
	S.push_back(3);

	Solution s;
	vector<vector<int> > sol = s.subsets(S);
	for (int i=0; i<sol.size(); ++i) {
		for (int j=0; j<sol[i].size(); ++j) {
			cout << sol[i][j] << " ";
		}
		cout << endl;
	}
}
