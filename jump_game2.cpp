#include <iostream>
using namespace std;

class Solution {
public:
	int jump(int A[], int n) {
		if (n == 0) return 0;

		for (int i=1; i<n; ++i) {
			if (A[i-1] <= 0) A[i] = A[i-1] - 1;
			else A[i] = max(A[i-1]-1, A[i]);
		}

		int step = 0;
		for (int i=0; i<n-1; ) {
			i = i + A[i];
			++step;
		}
		return step;
	}
};

int main()
{

}
