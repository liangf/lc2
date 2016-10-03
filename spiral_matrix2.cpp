#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int> > generateMatrix(int n) {
		vector<vector<int> > result;
		if (n == 0) return result;
		result.resize(n, vector<int>(n, 0));
		
		int start = 0;
		int left=0, right=n-1, top=0, bottom=n-1;
		while (left<right && top<bottom) {
			for (int i=left; i<right; ++i) {
				result[top][i] = ++start;
			}
			for (int i=top; i<bottom; ++i) {
				result[i][right] = ++start;
			}
			for (int i=right; i>left; --i) {
				result[bottom][i] = ++start;
			}
			for (int i=bottom; i>top; --i) {
				result[i][left] = ++start;
			}
			++left; --right; ++top; --bottom;	
		}	
		if (left == right) result[left][left] = ++start;
		return result;
	}
};

int main()
{
	Solution s;
	vector<vector<int> > res = s.generateMatrix(2);
	for (int i=0; i<res.size(); ++i) {
		for (int j=0; j<res[i].size(); ++j) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
}
