#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> grayCode(int n) {
		vector<int> result;
		if (n < 0) return result;
		result.push_back(0);
		
		for (int i=1; i<=n; ++i) {
			int a = 1<<(i-1);
			int nSize = result.size();
			for (int j=nSize-1; j>=0; --j) {
				result.push_back(result[j]+a);
			}	
		}
		return result;
	}
};

int main()
{
	Solution s;
	vector<int> res = s.grayCode(3);
	for (int i=0; i<res.size(); ++i) {
		cout << res[i] << endl;
	}
}
