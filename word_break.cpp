#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>
using namespace std;
/*
class Solution {
public:
	bool wordBreak(string s, unordered_set<string> &dict) {
		return dfs(s, dict, 0);
	}
	bool dfs(string s, unordered_set<string> &dict, int start) {
		if (start == s.length()) return true;	
		for (int i=start; i<s.length(); i++) {
			string words = s.substr(start, i-start+1);
			if (dict.find(words) != dict.end()) {
				if( dfs(s, dict, i+1) ) return true;
			}
		}	
		return false;
	}
};
*/
/*
class Solution {
public:
	bool wordBreak(string s, unordered_set<string> &dict) {
		return dfs(s, dict, 0);
	}
	bool dfs(string s, unordered_set<string> &dict, int start) {
		bool result = false;
		if (start == s.length()) return true;	
		for (int i=start; i<s.length(); i++) {
			string words = s.substr(start, i-start+1);
			if (dict.find(words) != dict.end()) {
				result = dfs(s, dict, i+1); 
			}
		}	
		return result;
	}
};
*/
/*
class Solution {
public:
	bool wordBreak(string s, unordered_set<string> &dict) {
		s = "^" + s;
		vector<bool> dp(s.size(), false);
		dp[0] = true;
		for (int i=1; i<s.size(); i++) {
			if (dp[i-1] == false) continue;
			for (int j=1; j<s.size(); j++) {
				string word = s.substr(i, j);
				if (dict.find(word) != dict.end()) {
					dp[i+j-1] = dp[i-1];
				}
			}
		}
		return dp[s.size()-1];
	}
};
*/
/*
class Solution {
public:
	bool wordBreak(string s, unordered_set<string> &dict) {
		vector<vector<bool> > dp(s.length(), vector<bool>(s.length(), false));

		for (int i=0; i<s.length(); ++i) {
			if (dict.find(s.substr(0, i+1)) != dict.end()) {
				dp[0][i] = true;
				continue;
			}
			for (int j=0; j<i; ++j) {
				if (dp[0][j]) {
					if (dict.find(s.substr(j+1, i-j)) != dict.end()) {
						dp[0][i] = true;
						break;
					}
				}
			}
		}
		return dp[0][s.length()-1];
	}
};
*/

class Solution {
public:
	bool wordBreak(string s, unordered_set<string> &dict) {
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
	unordered_set<string> dict = {"leet", "leets", "code"};
	string s = "leetscode";
	
	Solution S;
	cout << S.wordBreak(s, dict) << endl;
}
