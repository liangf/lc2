#include <iostream>
using namespace std;

class Solution {
public:
	int singleNumber(int A[], int n) {
		if (n == 1) return A[0];
		int result = A[0];
		for (int i=1; i<n; ++i) {
			result = result ^ A[i];
		}
		return result;
	}
};

int main()
{
	int A[] = {1, 2, 1, 2, 3};
	Solution s;
	cout << s.singleNumber(A, 5);
}
