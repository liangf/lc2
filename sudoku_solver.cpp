#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
	void solveSudoku(vector<vector<char> > &board) {
		dfs(board, 0, 0);	
	}
	bool dfs(vector<vector<char> > &board, int m, int n) {
		if (n == 9) return dfs(board, m+1, 0);
		if (m == 9) return true;
		
		if (board[m][n] != '.') return dfs(board, m, n+1);
		else {
			for (int i=1; i<=9; ++i) {
				board[m][n] = i+'0';
				if ( isValid(board, m, n) ) {
					if ( dfs(board, m, n+1) ) return true;
				}
				board[m][n] = '.';
			}
		}	
		return false;
	}
	bool isValid(vector<vector<char> > &board, int m, int n) {
		vector<int> row(10, 0), col(10, 0), sub(10, 0);
		for (int j=0; j<9; ++j) {
			if (board[m][j] != '.') {
				if (++row[board[m][j]-'0'] > 1) return false;
			}	
		}
		for (int i=0; i<9; ++i) {
			if (board[i][n] != '.') {
				if (++col[board[i][n]-'0'] > 1) return false;
			}
		}
		for (int i=(m/3)*3; i<(m/3)*3+3; ++i) {
			for (int j=(n/3)*3; j<(n/3)*3+3; ++j) {
				if (board[i][j] != '.') {
					++sub[board[i][j]-'0'];
					if (sub[board[i][j]-'0'] > 1) return false;
				}
			}
		}
		return true;
	}
};


/*
class Solution {
public:
	void solveSudoku(vector<vector<char> > &board) {
		dfs(board, 0, 0);
	}
	bool dfs(vector<vector<char> > &board, int m, int n) {
		if (n >= 9) return dfs(board, m+1, 0);
		if (m == 9) return true;
		
		if (board[m][n] == '.') {
			for (int i=1; i<=9; ++i) {
				board[m][n] = (char)(i+'0');
				if ( isValid(board, m, n) ) {
					if ( dfs(board, m, n+1) ) return true;
				}
				board[m][n] = '.';
			}
		}
		else return dfs(board, m, n+1);
		return false;
	}
	bool isValid(vector<vector<char> > &board, int m, int n) {
		for (int j=0; j<9; ++j) {
			if (j!=n && board[m][j]==board[m][n]) return false;
		}
		for (int i=0; i<9; ++i) {
			if (i!=m && board[i][n]==board[m][n]) return false;
		}
		for (int i=m/3*3; i<m/3*3+3; ++i) {
			for (int j=n/3*3; j<n/3*3+3; ++j) {
				if ((i!=m || j!=n) && board[m][n]==board[i][j]) return false;
			}
		}
		return true;
	}	
};
*/

int main()
{
	vector<vector<char> > board;
	vector<vector<char> > sol;
	vector<char> a(9, '.');
	a[0]='5';a[1]='3';a[4]='7';
	board.push_back(a);	

	vector<char> b(9, '.');
	b[0]='6';b[3]='1';b[4]='9';b[5]='5';
	board.push_back(b);	

	vector<char> c(9, '.');
	c[1]='9';c[2]='8';c[7]='6';
	board.push_back(c);	

	vector<char> d(9, '.');
	d[0]='8';d[4]='6';d[8]='3';
	board.push_back(d);	

	vector<char> e(9, '.');
	e[0]='4';e[3]='8';e[5]='3';e[8]='1';
	board.push_back(e);	

	vector<char> f(9, '.');
	f[0]='7';f[4]='2';f[8]='6';
	board.push_back(f);	

	vector<char> g(9, '.');
	g[1]='6';g[6]='2';g[7]='8';
	board.push_back(g);	

	vector<char> h(9, '.');
	h[3]='4';h[4]='1';h[5]='9';h[8]='5';
	board.push_back(h);	

	vector<char> I(9, '.');
	I[4]='8';I[7]='7';I[8]='9';
	board.push_back(I);	
	
	Solution s;
	s.solveSudoku(board);
	for (int i=0; i<9; i++) {
		for (int j=0; j<9; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}
