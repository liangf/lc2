#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int numTrees(int n) {
		vector<int> f(n+1, 0);
		f[0] = 1;	
		for (int k=1; k<=n; ++k) {
			for (int i=1; i<=k; ++i) {
				f[k] += f[i-1] * f[k-i];
			}
		}
		return f[n];
	}
};

int main()
{
	Solution s;
	for (int i=1; i<5; ++i) cout << s.numTrees(i) << endl;
}
