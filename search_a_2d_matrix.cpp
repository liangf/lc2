#include <iostream>
#include <vector>
using namespace std;
/*
class Solution {
public:
	bool searchMatrix(vector<vector<int> > &matrix, int target) {
		if (matrix.size() == 0) return false;
		int m=matrix.size(), n=matrix[0].size(), row=0;
		for (; row<m-1; ++row) {
			if (target>=matrix[row][0] && target<matrix[row+1][0]) {
				break;
			}
		}
		if (target > matrix[row][n-1]) return false;
		int left=0, right=n-1;
		while (left <= right) {
			int mid = left+(right-left)/2;
			if (target == matrix[row][mid]) return true;
			else if (target > matrix[row][mid]) left = mid+1;
			else right = mid - 1;
		}
		return false;
	}
};
*/

class Solution {
public:
	bool searchMatrix(vector<vector<int> > &matrix, int target) {
		if (matrix.size() == 0) return false;
		int m=matrix.size(), n=matrix[0].size(), row=0;

		int left=0, right=m-1;
		while (left <= right) {
			int mid = left + (right-left)/2;
			if (target < matrix[mid][0]) right = mid -1;
			else if (target > matrix[mid][0]) left = mid + 1;
			else return true; 
		}
		if (right < 0) return false;
		row = right;

		left=0, right=n-1;
		while (left <= right) {
			int mid = left + (right-left)/2;
			if (target < matrix[row][mid]) right = mid -1;
			else if (target > matrix[row][mid]) left = mid + 1;
			else return true; 
		}
		return false;
	}
};

int main()
{
	vector<vector<int> > matrix;
	vector<int> row;
	row.push_back(1);
	matrix.push_back(row);
	row.clear();

	row.push_back(3);
	matrix.push_back(row);
	
	Solution s;
	cout << s.searchMatrix(matrix, 3);
}
