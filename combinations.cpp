#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int> > combine(int n, int k) {
		vector<int> result;
		vector<vector<int> > solution;
		if (k<=0 || k>n) return solution;
		dfs(n, k, 1, result, solution);
	}
	void dfs(int n, int k, int start, vector<int> &result, vector<vector<int> > &solution) {
		if (result.size() == k) {
			solution.push_back(result);
			return;
		}

		for (int i=start; i<=n; ++i) {
			result.push_back(i);
			dfs(n, k, i+1, result, solution);
			result.pop_back();
		}
	}
};

int main()
{

}
