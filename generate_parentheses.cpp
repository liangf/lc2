#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	vector<string> generateParenthesis(int n) {
		string s="";
		vector<string> result;
		dfs(s, n, 0, 0, result);
		return result;
	}
	void dfs(string &s, int n, int left, int right, vector<string> &result) {
		if (right > left) return;
		if (left==n && right==n) {
			result.push_back(s);
			return;
		}
		if (left < n) {
			s.push_back('(');
			dfs(s, n, left+1, right, result);
			s.pop_back();
		}
		if (right < n) {
			s.push_back(')');
			dfs(s, n, left, right+1, result);
			s.pop_back();
		}
	}
};

int main()
{
	Solution s;
	vector<string> res = s.generateParenthesis(4);
	for (int i=0; i<res.size(); ++i) {
		cout << res[i] << endl;
	}
}
