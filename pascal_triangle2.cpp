#include <iostream>
#include <vector>
using namespace std;

/*
class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> row;
		row.push_back(1);

		for (int i=1; i<=rowIndex; ++i) {
			vector<int> new_row(i+1, 1);
			for (int j=1; j<row.size(); ++j) {
				new_row[j] = row[j] + row[j-1];
			}
			row = new_row;	
		}
		return row;
	}
};
*/

class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> row;
		row.push_back(1);

		for (int i=1; i<=rowIndex; ++i) {
			row.resize(i+1, 1);
			for (int j=row.size()-2; j>0; --j) {
				row[j] = row[j] + row[j-1];
			}
		}
		return row;
	}
};


int main()
{
	Solution s;
	vector<int> row = s.getRow(5);
	for (int i=0; i<row.size(); ++i) {
		cout << row[i] << " "; 
	}
	cout << endl;
}
