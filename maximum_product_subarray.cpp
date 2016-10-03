#include <iostream>
#include <climits>
using namespace std;
/*
class Solution {
public:
	int maxProduct(int A[], int n) {
		if (n <= 0) return INT_MIN;

		int product = 1, product2 = INT_MIN;
		int result = INT_MIN;
		for (int i=0; i<n; ++i) {
			if (A[i]<0 && product2==INT_MIN) {
				product2 = 1;
				product *= A[i];
				result = max(result, product);
				continue;
			}
			if (A[i] == 0) {
				product = 1;	
				product2 = INT_MIN;
				result = max(result, 0);
				continue;
			}
			product *= A[i];
			if (product2 != INT_MIN) product2 *= A[i];
//cout << A[i] << ":";
//cout << product << " " << product2 << endl;
			result = max( result, max(product, product2) );
		}		

		return result;
	}
};
*/

class Solution {
public:
	int maxProduct(int A[], int n) {
		if (n < 1) return INT_MIN;
		
		int local=1, local2 = INT_MIN;
		int global = INT_MIN;

		for (int i=0; i<n; ++i) {
			local *= A[i];
			if (local2 != INT_MIN) local2 *= A[i];
			global = max( local2, max(local, global) );
			if (A[i] == 0) {
				local = 1;
				local2 = INT_MIN;
			}
			if (A[i]<0 && local2==INT_MIN) {
				local2 = 1;
			} 
		}
		return global;
	}
};

int main()
{
	int A[] = {2, 3, -1, 4, -1, -20};
	Solution s;
	cout << s.maxProduct(A, 6) << endl;
}  
