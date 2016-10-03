#include <iostream>
#include <vector>
using namespace std;
/*
class Solution {
public:
	int numDecodings(string s) {
		if (s.length() == 0) return 0;		
		s = "#" + s;
		vector<int> dp(s.length(), 1);
		if (s[1] == '0') dp[1] = 0;		
	
		for (int i=2; i<s.length(); ++i) {
			int sum = (s[i-1]-'0')*10 + s[i]-'0';
			if (s[i] == '0') {
				dp[i] = dp[i-2];
				if (sum == 0) dp[i] = 0;
			}
			else {
				dp[i] = dp[i-1];
				if (sum>=1 && sum<=26) dp[i] = dp[i-1] + dp[i-2];
			}
		}
		return dp[s.length()-1];
	}
};
*/

class Solution {
public:
	int numDecodings(string s) {
		if (s.length() == 0) return 0;		
		s = "#" + s;
		vector<int> dp(s.length(), 1);
		if (s[1] == '0') dp[1] = 0;		
	
		for (int i=2; i<s.length(); ++i) {
			int sum = (s[i-1]-'0')*10 + s[i]-'0';
			if (s[i] == '0') {
				if (sum>=10 && sum<=26) dp[i] = dp[i-2];
				else dp[i] = 0;
			}
			else {
				dp[i] = dp[i-1];	
				if (sum>=10 && sum<=26) dp[i] = dp[i-1] + dp[i-2];
			}
		}
		return dp[s.length()-1];
	}
};

int main()
{
	//string s = "12";
	//string s = "0";
	//string s = "10";
	//string s = "01";
	//string s = "101";
	//string s = "10010";
	//string s = "110";
	string s = "230";
	Solution S;
	cout << S.numDecodings(s);
}
