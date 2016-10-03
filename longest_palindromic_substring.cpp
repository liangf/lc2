#include <iostream>
#include <vector>
using namespace std;
/*
// Time limit exceeded
class Solution {
public:
	string longestPalindrome(string s) {
		if (s.length() == 0) return 0;
		string result = "";
		vector<vector<bool> > p(s.length(), vector<bool>(s.length(), false));
		for (int i=s.size()-1; i>=0; --i) {
			for (int j=s.size()-1; j>=i; --j) {
				//p[i][j] = (i+1>j-1) || (s[i]==s[j]&&p[i+1][j-1]);
				p[i][j] = (s[i]==s[j] && ((i+1>j-1)||p[i+1][j-1]));
				if (p[i][j]) result = i-j+1>s.length() ? s.substr(i, j-i+1) : result;
			}
		}
		return result;
	}
};
*/

class Solution {
public:
	string longestPalindrome(string s) {
		string result = "";
		for (int i=0; i<s.length(); ) {
			int left=i-1, right=i+1;
			while (left>=0 && s[left]==s[i]) --left;
			while (right<s.length() && s[right]==s[i]) ++right;
			i = right;	
			while (left>=0 && right<s.length() && s[left]==s[right]) {
				--left;
				++right;
			}
			if (right-left-1 > result.length()) result = s.substr(left+1, right-left-1);
		}
		return result;
	}
};


int main()
{

}
