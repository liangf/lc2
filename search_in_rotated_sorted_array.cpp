#include <iostream>
using namespace std;
/*
class Solution {
public:
	int search(int A[], int n, int target) {
		if (n <= 0) return -1;	
	
		int left, right, mid;
		left = 0;
		right = n-1;
		while (left <= right) {
			mid = left + (right-left)/2;		
			if (A[mid] == target) return mid;
			if (A[mid] > A[right]) {
				if (target<A[mid] && target>=A[left]) right = mid - 1;
				else left = mid + 1;
			}
			else {
				if (target>A[mid] && target<=A[right]) left = mid + 1;
				else right = mid - 1;
			}
		}
		return -1;
	}
};
*/

class Solution {
public:
	int search(int A[], int n, int target) {
		if (n <= 0) return -1;
	
		int left=0, right=n-1, mid;
		while (left <= right) {
			int mid = left+(right-left)/2;
			if (target == A[mid]) return mid;
			if (A[mid] > A[right]) {
				if (target > A[mid]) left = mid + 1;
				else {
					if (target >= A[left]) right = mid - 1;
					else left = mid + 1;
				}
			}
			else {
				if (target < A[mid]) right = mid - 1;
				else {
					if (target <= A[right]) left = mid + 1;
					else right = mid - 1;
				}
			}
		}
		return -1;
	}
};

int main()
{
	Solution s;
	//int A[] = {4, 5, 1, 2, 3};
	//int A[] = {3, 4, 5, 1, 2};
	//int A[] = {3, 4, 5, 6, 1, 2};
	int A[] = {5, 6, 1, 2, 3, 4};
	
	cout << s.search(A, 6, 6) << endl;
}
