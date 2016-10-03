#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int> > generate(int numRows) {
		vector<vector<int> > sol;
		if (numRows <= 0) return sol;
		sol.push_back(vector<int>(1, 1));		

		for (int i=1; i<numRows; ++i) {
			vector<int> old_row = sol.back();
			vector<int> new_row(i+1, 1);
			for (int j=1; j<old_row.size(); ++j) {
				new_row[j] = old_row[j] + old_row[j-1];
			}
			sol.push_back(new_row);
		}
		return sol;
	}
};

int main()
{
	Solution s;
	vector<vector<int> > sol = s.generate(5);
	for (int i=0; i<sol.size(); ++i) {
		for (int j=0; j<sol[i].size(); ++j) {
			cout << sol[i][j] << " ";
		}
		cout << endl;
	}
}
