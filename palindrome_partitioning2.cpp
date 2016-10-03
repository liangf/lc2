#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;
/*
class Solution {
public:
	int minCut(string s) {
		if (s.length() == 0) return 0;
		vector<int> dp(s.length()+1, INT_MAX);
		dp[s.length()] = -1;
		for (int i=s.length()-1; i>=0; --i) {
			for (int j=i; j<s.length(); ++j) {
				if (isPalindrome(s, i, j)) {
					dp[i] = min(dp[i], 1+dp[j+1]);
				}
			}	
		}
		return dp[0];
	}
	bool isPalindrome(string &s, int begin, int end) {
		while (begin <= end) {
			if (s[begin++] != s[end--]) return false;
		}
		return true;
	}
};
*/

/*
class Solution {
public:
	int minCut(string s) {
		if (s.length() == 0) return 0;
		vector<int> dp(s.length()+1, INT_MAX);
		vector<vector<bool> > P(s.length(),vector<bool>(s.length(),false));
		dp[s.length()] = -1;

		for (int i=s.length()-1; i>=0; --i) {
			for (int j=i; j<s.length(); ++j) {
				P[i][j] = (s[i]==s[j] && ((i+1>j-1)||P[i+1][j-1]));
				if (P[i][j]) {
					dp[i] = min(dp[i], 1+dp[j+1]);
				}	
			}
		}
		return dp[0];
	}
};
*/

class Solution {
public:
	int minCut(string s) {
		if (s.length() == 0) return 0;
		vector<int> dp(s.length()+1, INT_MAX);
		vector<vector<bool> > P(s.length(),vector<bool>(s.length(),false));
		dp[s.length()] = -1;

		for (int i=s.length()-1; i>=0; --i) {
			//for (int j=i; j<s.length(); ++j) {
			for (int j=s.length(); j>=i; --j) {
				P[i][j] = (s[i]==s[j] && ((i+1>j-1)||P[i+1][j-1]));
				if (P[i][j]) {
					dp[i] = min(dp[i], 1+dp[j+1]);
				}	
			}
		}
		return dp[0];
	}
};

int main()
{
	string s = "aab";
	Solution S;
	cout << S.minCut(s) << endl;
}
