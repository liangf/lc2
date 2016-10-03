#include <iostream>
using namespace std;

class Solution {
public:
	bool canJump(int A[], int n) {
		if (n == 0) return true;

		for (int i=1; i<n; ++i) {
			if (A[i-1] == 0) A[i] = -1;
			else A[i] = max(A[i-1]-1, A[i]);
		}
		return A[n-1] >= 0;
	}
};

int main()
{

}
