#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int> > permute(vector<int> &num) {
		sort(num.begin(), num.end());
		vector<bool> visited(num.size(), false);
		vector<int> result;
		vector<vector<int> > solution;

		dfs(num, visited, result, solution);
		return solution;	
	}
	void dfs(vector<int> &num, vector<bool> &visited, vector<int> &result, 
				vector<vector<int> > &solution) {
		if (result.size() == num.size()) {
			solution.push_back(result);
			return;
		}

		for (int i=0; i<num.size(); ++i) {
			if ( !visited[i] ) {
				visited[i] = true;
				result.push_back(num[i]);
				dfs(num, visited, result, solution);
				result.pop_back();
				visited[i] = false;
			}
		}
	}
};


int main()
{

}
