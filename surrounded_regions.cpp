#include <iostream>
#include <vector>
using namespace std;

/*
// Runningtime Error
class Solution {
public:
	void solve(vector<vector<char> > &board) {
		if (board.size() == 0) return;
		int nRow=board.size(), nCol=board[0].size();

		for (int j=0; j<nCol; ++j) {
			if (board[0][j] == 'O') dfs(board, 0, j);
			if (board[nRow-1][j] == 'O') dfs(board, nRow-1, j);
		}
		for (int i=1; i<nRow-1; ++i) {
			if (board[i][0] == 'O') dfs(board, i, 0);
			if (board[i][nCol-1] == 'O') dfs(board, i, nCol-1);
		}
		for (int i=0; i<nRow; ++i) {
			for (int j=0; j<nCol; ++j) {
				if (board[i][j] == '#') board[i][j] = 'O';
				else if (board[i][j] == 'O') board[i][j] = 'X';
			}
		}
	}
	void dfs(vector<vector<char> > &board, int m, int n) {
		if (m<0 || m>=board.size() || n<0 || n>=board[0].size()) return;
		if (board[m][n]=='#'|| board[m][n]=='X') return;		

		board[m][n] = '#';
		dfs(board, m, n+1);
		dfs(board, m+1, n);
		dfs(board, m, n-1);
		dfs(board, m-1, n);
	}
};
*/

/*
class Solution {
public:
	void solve(vector<vector<char> > &board) {
		if (board.size() == 0) return;
		int nRow=board.size(), nCol=board[0].size();

		for (int j=0; j<nCol; ++j) {
			if (board[0][j] == 'O') dfs(board, 0, j);
			if (board[nRow-1][j] == 'O') dfs(board, nRow-1, j);
		}
		for (int i=1; i<nRow-1; ++i) {
			if (board[i][0] == 'O') dfs(board, i, 0);
			if (board[i][nCol-1] == 'O') dfs(board, i, nCol-1);
		}
		for (int i=0; i<nRow; ++i) {
			for (int j=0; j<nCol; ++j) {
				if (board[i][j] == '#') board[i][j] = 'O';
				else if (board[i][j] == 'O') board[i][j] = 'X';
			}
		}
	}
	void dfs(vector<vector<char> > &board, int i, int j) {
		if (board[i][j] == 'O') {
			board[i][j] = '#';
			if (i<board.size()-1 && board[i+1][j]=='O')
				dfs(board, i+1, j);
			if (j<board[0].size()-1 && board[i][j+1]=='O')
				dfs(board, i, j+1);
			if (i>0 && board[i-1][j] == 'O')
				dfs(board, i-1, j);
			if (j>1 && board[i][j-1] == 'O')
				dfs(board, i, j-1);
		}
	}
};
*/

class Solution {
public:
	void solve(vector<vector<char> > &board) {
		if (board.size() <= 2) return;
    	int nRow = board.size();
        int nCol = board[0].size();
            
        for(int j=0; j<nCol; ++j) {
        	if(board[0][j] == 'O')  dfs(1, j, board);
        	if(board[nRow-1][j] == 'O') dfs(nRow - 2, j, board);
		}
       	for(int i = 1; i<nRow-1; ++i) {
        	if(board[i][0] == 'O') dfs(i, 1, board);
        	if(board[i][nCol-1] == 'O') dfs(i, nCol-2, board);
		}   
        for(int i=1; i<nRow-1; i++){
        	for(int j=1; j<nCol-1; j++) {
            	if(board[i][j] == '#') board[i][j] = 'O';
            	else if(board[i][j] == 'O') board[i][j] = 'X';
			}
        }
	}
    void dfs(int i, int j, vector<vector<char> > &board){
    	int nRow = board.size();
   		int nCol = board[0].size();
   		if(i<=0 || i>=nRow-1 || j<=0 || j>=nCol-1) return;
        if (board[i][j]=='#' || board[i][j]=='X') return;	

		board[i][j] = '#';
        dfs(i - 1, j, board);  
        dfs(i + 1, j, board);
        dfs(i, j - 1, board);
        dfs(i, j + 1, board);
	}
};


int main()
{

}
