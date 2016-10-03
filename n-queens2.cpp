#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
	int totalNQueens(int n) {
		int result = 0;
		vector<int> row(n, -1);
		dfs(0, row, result);	
		return result;
	}
	void dfs(int m, vector<int> &row, int &sum) {
		if (m == row.size()) {
			++sum;
			return;
		}
		for (int j=0; j<row.size(); ++j) {
			row[m] = j;
			if ( check(m, row) ) dfs(m+1, row, sum);
		}
	}
	bool check(int m, vector<int> &row) {
		for (int i=0; i<m; ++i) {
			if (row[m]==row[i] || abs(m-i)==abs(row[m]-row[i])) return false;
		}
		return true;
	}
};

int main()
{
	Solution s;
	cout << s.totalNQueens(4) << endl;
}
