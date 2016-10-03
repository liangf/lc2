#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool isValidSudoku(vector<vector<char> > &board) {
		for (int i=0; i<9; ++i) {
			vector<bool> map(10, false);
			for (int j=0; j<9; ++j) {
				if (board[i][j] != '.'){
					if (map[board[i][j]-'0']) return false;
					map[board[i][j]-'0'] = true;
				}
			}
		}
		for (int j=0; j<9; ++j) {
			vector<bool> map(10, false);
			for (int i=0; i<9; ++i) {
				if (board[i][j] != '.'){
					if (map[board[i][j]-'0']) return false;
					map[board[i][j]-'0'] = true;
				}
			}
		}
		for (int m=0; m<9; m+=3) {
			for (int n=0; n<9; n+=3) {
				vector<bool> map(10, false);
				for (int i=m; i<m+3; ++i) {
					for (int j=n;j<n+3; ++j) {
						if (board[i][j] != '.'){
							if (map[board[i][j]-'0']) return false;
							map[board[i][j]-'0'] = true;
						}
					}
				}
			}	
		}
		return true;
	}
};

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
	cout << s.isValidSudoku(board) << endl;
}
