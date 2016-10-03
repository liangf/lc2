#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
	vector<string> wordBreak(string s, unordered_set<string> &dict) {
		string result = "";
		vector<string> solution;
		if ( !canWordBreak(s, dict) ) return solution;
		dfs(s, dict, result, 0, solution);
		return solution;
	}
	void dfs(string &s, unordered_set<string> &dict, string &result,
				int start, vector<string> &solution) {
		if (start == s.length()) {
			result.resize(result.length()-1);
			solution.push_back(result);
			result = result + " ";
			return;
		}
		for (int i=start; i<s.length(); ++i) {
			if (dict.find(s.substr(start, i-start+1)) != dict.end()) {
				result += s.substr(start, i-start+1);
				result += " ";
				dfs(s, dict, result, i+1, solution);
				// len = i-start+1+1;
				result.resize(result.length()-i+start-2);
			}
		}
	}
	bool canWordBreak(string s, unordered_set<string> &dict) {
		if (s.length() == 0) return true;

		vector<bool> dp(s.length(), false);
		for (int i=0; i<s.length(); ++i) {
			if (dict.find(s.substr(0, i+1)) != dict.end()) {
				dp[i] = true;
				continue;
			}
		// dp[i] = dp[j] && dict.find(substr(j+1, i-j))!=dict.end();
			for (int j=0; j<i; ++j) {
				if (dp[j]) {
					if (dict.find(s.substr(j+1, i-j)) !=dict.end()) {
						dp[i] = true;
						break;
					}
				}
			}
		}
		return dp[s.length()-1];
	}
};

int main()
{
	string s = "catsanddog";
	unordered_set<string> dict;
	dict.insert("cat");
	dict.insert("cats");
	dict.insert("and");
	dict.insert("sand");
	dict.insert("dog");
	
	Solution S;
	vector<string> sol = S.wordBreak(s, dict);
	for (int i=0; i<sol.size(); ++i) {
		cout << sol[i] << endl;
	}
}
