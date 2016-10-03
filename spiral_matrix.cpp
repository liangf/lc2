#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int> > &matrix) {
		vector<int> result;
		if (matrix.size() == 0) return result;
		int left=0, right=matrix[0].size()-1;
		int top=0, bottom=matrix.size()-1;

		while (left<right && top<bottom) {
			for (int i=left; i<right; ++i) {
				result.push_back(matrix[top][i]);
			}
			for (int i=top; i<bottom; ++i) {
				result.push_back(matrix[i][right]);
			}
			for (int i=right; i>left; --i) {
				result.push_back(matrix[bottom][i]);
			}
			for (int i=bottom; i>top; --i) {
				result.push_back(matrix[i][left]);
			}
			++left; --right; ++top; --bottom;
		}
		if (left == right) {
			for (int i=top; i<=bottom; ++i) {
				result.push_back(matrix[i][left]);
			}
		}
		else if (top == bottom) {
			for (int i=left; i<=right; ++i) {
				result.push_back(matrix[top][i]);
			}
		}
	}
};

int main()
{

}
