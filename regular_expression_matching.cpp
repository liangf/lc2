#include <iostream>
#include <assert.h>
using namespace std;

class Solution {
public:
	bool isMatch(string s, string p) {
		if (p==NULL || s==NULL) return false;
		if (p.length() == 0) return s.length() == 0;
		
		vector<vector<bool> > dp(s.length()+1, vector<bool>(p.length()+1, false));
		dp[0][0] = true;
		for (int i=1; i<=s.length(); ++i) {
			for (int j=1; j<=p.length(); ++j) {
				if (p[j] == s[i]) dp[i][j] = true;
				else {
					if (p[j] == '*') dp[i][j] = j>=2 && dp[i-2][j-3];
					else {
						if (p[j]=='.' || p[j]==s[j]) dp[i][j] = i>=1 && j>=1 && dp[i-1][j-1];
						else dp[i][j] = false;
					}
				}
			}
		}
		return dp[s.length()][p.length()];
	}
};

class Solution {
public:
	bool isMatch(string s, string p) {
		cout << s << "-" << p << endl;
		if (p.length() == 0) return s.length() == 0;
		
		if (p.length() == 1) {
			if (p[0] == '*') return false;
			else return s.length()==1 && (p[0]=='.' || s[0]==p[0]);
		}
		else {
			if (p[1] == '*') {
				if ( isMatch(s, p.substr(2)) ) return true;
				for (int i=0; i<s.length(); ++i) {
					if (p[0] != '.' && p[0] != s[i]) break;
					if ( isMatch(s.substr(i+1), p.substr(2)) ) return true;
				}
				return false;
			}
			else {
				if (s.length() < 1) return false;
				return (p[0]=='.' || p[0]==s[0]) && isMatch(s.substr(1), p.substr(1));
			}
		}
	}
};

int main() 
{
	//string s = "aaa";
	//string p = "a*";	

	//string s = "aaa";
	//string p = "aaa";	
	
	//string s = "aa";
	//string p = ".*";	

	//string s = "aab";
	//string p = "c*a*b";	

	//string s = "aaa";
	//string p = "a*a";	

	//string s = "aaa";
	//string p = "ab*ac*a";	

	//string s = "a";
	//string p = "a.";	

	//string s = "a";
	//string p = ".";	

	//string s = "ab";
	//string p = ".*..";	

	//string s = "ab";
	//string p = ".*..c*";	

	string s = "a";
	string p = ".*..a*";	

	//string s = "aasdfasdfasdfasdfas";
	//string p = "aasdf.*asdf.*asdf.*asdf.*s";	

	//string s = "aaa";
	//string p = "a.a";	

	//string s = "";
	//string p = ".b*";	

	//string s = "a";
	//string p = "ab*";	

	Solution S;
	cout << S.isMatch(s, p) << endl;
}
