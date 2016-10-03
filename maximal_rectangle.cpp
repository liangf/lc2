#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int maximalRectangle(vector<vector<char> > &matrix) {
		if (matrix.size() == 0) return 0;
		int row = matrix.size();
		int col = matrix[0].size();
		vector<vector<int> > left(row, vector<int>(col, 0));

		for (int i=0; i<row; ++i) {
			for (int j=0; j<col; ++j) {
				if (matrix[i][j] == '1') {
					if (j == 0) left[i][j] = 1;
					else left[i][j] = left[i][j-1] + 1;
				}
			}
		}
		int maxArea = 0;
		for (int i=0; i<row; ++i) {
			for (int j=0; j<col; ++j) {
				if (matrix[i][j] == '1') {
					int l=col, h=i;
					while (h>=0 && left[h][j]>0) {
						l = min(l, left[h][j]);
						maxArea = max(maxArea, l*(i-h+1));
						--h;
					}
				}	
			}
		}
		return maxArea;
	}
};

int main()
{
	vector<vector<char> > matrix;
	vector<char> row;
	row.push_back('0');
	row.push_back('1');
	matrix.push_back(row);

	Solution s;
	cout << s.maximalRectangle(matrix);
}
