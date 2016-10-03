#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<string> > partition(string s) {
		vector<string> result;
		vector<vector<string> > solution;
		dfs(s, 0, result, solution);
		return solution;
	}
	void dfs(string &s, int start, vector<string> &result, 
			vector<vector<string> > &solution) {
		if (start == s.length()) {
			solution.push_back(result);
			return;
		}		

		for (int i=start; i<s.length(); ++i) {
			if (isPalindrome(s.substr(start, i-start+1))) {
				result.push_back(s.substr(start, i-start+1));
				dfs(s, i+1, result, solution);
				result.pop_back();
			}
		}
	}
	bool isPalindrome(string s) {
		for (int i=0; i<s.length()/2; ++i) {
			if (s[i] != s[s.length()-1-i]) return false;
		}
		return true;
	}
};

int main()
{
	string s = "aab";
	Solution S;
	vector<vector<string> > sol = S.partition(s);
	for (int i=0; i<sol.size(); ++i) {
		for (int j=0; j<sol[i].size(); ++j) {
			cout << sol[i][j] << " ";
		}
		cout << endl;
	}
}
