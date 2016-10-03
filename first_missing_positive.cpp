#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
	int firstMissingPositive(int A[], int n) {
		for (int i=0; i<n; ++i) {
			while (A[i]-1!=i && A[i]>0 && A[i]-1<n) {
				if (A[i] == A[ A[i]-1 ]) break;
				swap(A[i], A[ A[i]-1 ]);
			}
		}
		for (int i=0; i<n; ++i) {
			if (A[i]-1 != i) return i+1;
		}
		return n+1;
	}
};

int main()
{
	//int A[] = {1, 2, 0};
	//int A[] = {3, 4, -1, 1};
	int A[] = {1, 1, 1};
	
	Solution s;
	cout << s.firstMissingPositive(A, 4);
}
