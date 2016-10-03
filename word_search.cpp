#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
	bool exist(vector<vector<char> > &board, string word) {
		if (board.size() == 0) return false;
		vector<vector<bool> > visited(board.size(), vector<bool>(board[0].size(), false));
		for (int i=0; i<board.size(); ++i) {
			for (int j=0; j<board[i].size(); ++j) {
				if (dfs(board, word, visited, i, j, 0)) return true;
			}
		}
		return false;
	}
	bool dfs(vector<vector<char> > &board, string &word, 
				vector<vector<bool> > &visited, int i, int j, int start) {
		if (start == word.length()) return true;
		if (i>=board.size() || i<0 ||j>=board[0].size() || j<0) return false;
		if ( visited[i][j] ) return false;
		if (board[i][j] != word[start]) return false;

		visited[i][j] = true;
		bool isExist = false;
		isExist = 	dfs(board, word, visited, i, j+1, start+1) ||
					dfs(board, word, visited, i+1, j, start+1) ||
					dfs(board, word, visited, i, j-1, start+1) ||
					dfs(board, word, visited, i-1, j, start+1);
		visited[i][j] = false;
		return isExist;
	}
};

int main()
{

}
