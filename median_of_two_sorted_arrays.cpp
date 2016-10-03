#include <iostream>
using namespace std;

class Solution {
public:
	double findMedianSortedArrays(int A[], int m, int B[], int n) {
		if ((m+n)%2 == 1) return select(A, m, B, n, (m+n)/2+1);
		else return (select(A, m, B, n, (m+n)/2) + select(A, m, B, n, (m+n)/2+1))/2.0;
	}
	int select(int A[], int m, int B[], int n, int k) {
		if (m > n) return select(B, n, A, m, k);
		if (m == 0) return B[k-1];
	
		if (k == 1) return min(A[0], B[0]); 
		int i = min(m, k/2), j = k-i;
		if (A[i-1] < B[j-1]) return select(A+i, m-i, B, n, k-i);
		else if (A[i-1] > B[j-1]) return select(A, m, B+j, n-j, k-j);
		else return A[i-1];
	}
};

int main()
{
	//int A[] = {1, 2};
	//int A[] = {};
	//int B[] = {1, 2, 3};

	int A[] = {1};
	int B[] = {1};

	//int A[] = {2, 3};
	//int B[] = {};

	Solution s;
	cout << s.findMedianSortedArrays(A, 1, B, 1) << endl;
}
