#include <iostream>
using namespace std;

/*
class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		if (s1.length()+s2.length() != s3.length()) return false;
		int m = s1.length(), n = s2.length();
		bool dp[m+1][n+1];
		dp[0][0] = true;	
		for (int i=1; i<=m; ++i) dp[i][0] = dp[i-1][0] && s1[i-1]==s3[i-1];
		for (int j=1; j<=n; ++j) dp[0][j] = dp[0][j-1] && s2[j-1]==s3[j-1];

		for (int i=1; i<=m; ++i) {
			for (int j=1; j<=n; ++j) {
				dp[i][j] = (dp[i-1][j] && s1[i-1]==s3[i+j-1]) ||
						   (dp[i][j-1] && s2[j-1]==s3[i+j-1]); 
			}
		}
		return dp[m][n];
	}
};
*/

class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		if (s1.length()+s2.length() != s3.length()) return false;
		int m = s1.length(), n = s2.length();
		bool dp[m+n+1];
		dp[0] = true;
		for (int i=0; i<=m; ++i) dp[] = dp[] && s1[]

		for (int i=1; i<=m; ++i) {
			for (int j=1; j<=n; ++j) {
				dp[] = dp[i-1+j] && s1[i-1]==s3[i+j-1] ||
					   dp[] && s2[j-1]==s3[i+j-1];
			} 
		}
		return dp[m+n];	
	}
};

int main()
{

}
