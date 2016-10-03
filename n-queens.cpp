#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
/*
class Solution {
public:
	vector<vector<string> > solveNQueens(int n) {
		vector<int> row(n, -1);
		vector<string> board(n, string(n, '.'));
		vector<vector<string> > sol;
		dfs(0, row, board, sol);
		return sol;
	}
	void dfs(int i, vector<int>&row, vector<string> &board, vector<vector<string> > &sol) {
		if (i == board.size()) {
			sol.push_back(board);
			return;
		} 

		for (int j=0; j<row.size(); ++j) {
			if ( check(row, i, j) ) {
				row[i] = j;
				board[i][j] = 'Q';
				dfs(i+1, row, board, sol);
				board[i][j] = '.';
				row[i] = -1;	
			}
		}
	}
	bool check(vector<int> &row, int m, int n) {
		for (int i=0; i<row.size(); ++i) {
			if (row[i] >= 0) {
				if (row[i]==n || abs(n-row[i])==abs(m-i)) return false;
			}
		}
		return true;
	}
};
*/

class Solution {
public:
	vector<vector<string> > solveNQueens(int n) {
		vector<int> row(n, -1);
		vector<string> board(n, string(n, '.'));
		vector<vector<string> > sol;
		dfs(0, row, board, sol);
		return sol;
	}
	void dfs(int i, vector<int>&row, vector<string> &board, vector<vector<string> > &sol) {
		if (i == board.size()) {
			sol.push_back(board);
			return;
		} 
		for (int j=0; j<row.size(); ++j) {
			row[i] = j;
			board[i][j] = 'Q';
			if ( check(row, i) ) dfs(i+1, row, board, sol);
			board[i][j] = '.';
			row[i] = -1;	
		}
	}
	bool check(vector<int> &row, int m) {
		for (int i=0; i<m; ++i) {
			if (row[i]==row[m] || abs(row[m]-row[i])==abs(m-i)) return false;
		}
		return true;
	}
};

int main()
{
	Solution s;
	
	vector<vector<string> > sol = s.solveNQueens(4);
	cout << sol.size() << endl;	
	
	for (int i=0; i<sol.size(); ++i) {
		for (int j=0; j<sol[i].size(); ++j) {
			cout << sol[i][j] << endl;
		}
		cout << endl;
	}
}
