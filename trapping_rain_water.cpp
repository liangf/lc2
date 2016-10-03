#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
	int trap(int A[], int n) {
		int left[n], right[n];
		left[0] = 0, right[n-1] = 0;

		for (int i=1; i<n; ++i) {
			left[i] = max(A[i-1], left[i-1]);
		}
		for (int i=n-2; i>=0; --i) {
			right[i] = max(A[i+1], right[i+1]);
		}

		int result = 0;
		for (int i=0; i<n; ++i) {
			if (min(left[i], right[i]) > A[i])
				result += min(left[i], right[i])-A[i];	
		}
		return result;
	}
};

int main()
{
	int A[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	Solution s;
	cout << s.trap(A, 12);	
}
