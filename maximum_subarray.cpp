#include <iostream>
#include <climits>
using namespace std;


class Solution {
public:
	int maxSubArray(int A[], int n) {
		if (n < 1) return INT_MIN;

		int local = A[0];
		int global = A[0];
		for (int i=1; i<n; ++i) {
			local += A[i];
			local = max(A[i], local);
			global = max(local, global);
		}
		return global;
	}
};

int main()
{
	int A[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};	
	
	Solution s;
	cout << s.maxSubArray(A, 9) << endl;
}
