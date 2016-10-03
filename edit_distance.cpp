#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int minDistance(string word1, string word2) {
		word1 = "#" + word1;
		word2 = "#" + word2;
		int m = word1.size(), n = word2.size();
		vector<vector<int> > dp(m, vector<int>(n, 0));

		for (int i=0; i<m; ++i) dp[i][0] = i;
		for (int j=0; j<n; ++j) dp[0][j] = j;		

		for (int i=1; i<m; ++i) {
			for (int j=1; j<n; ++j) {
				if (word1[i] == word2[j]) dp[i][j] = dp[i-1][j-1];
				else dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
			}
		}
		return dp[m-1][n-1];
	}
};

int main()
{
	//string word1 = "hello";
	//string word2 = "eloh";
	
	string word1 = "a";
	string word2 = "b";

	Solution s;
	cout << s.minDistance(word1, word2);
}
