#include <iostream>
using namespace std;

class Solution {
public:
	int numDistinct(string S, string T) {
		S = "#" + S;
		T = "#" + T;
		int m = S.length(), n = T.length();
		int dp[m][n];
		for (int j=0; j<n; ++j) dp[0][j] = 0;
		for (int i=0; i<m; ++i) dp[i][0] = 1;

		for (int i=1; i<m; ++i) {
			for (int j=1; j<n; ++j) {
				if (S[i] == T[j]) dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
				else dp[i][j] = dp[i-1][j];
			}
		}
		return dp[m-1][n-1];
	}
};

int main()
{
	string S = "CCC";
	string T = "C";
	
	Solution s;
	cout << s.numDistinct(S, T) << endl;
}
