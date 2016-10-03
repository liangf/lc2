#include <iostream>
using namespace std;
/*
class Solution {
public:
	bool search(int A[], int n, int target) {
		if (n <= 0) return false;

		int left, right, mid;
		left = 0;
		right = n - 1;
		while (left <= right) {
			mid = left + (right-left)/2;
			if (target == A[mid]) return true;
			if (A[mid] == A[right]) {
				--right;
			}
			else if (A[mid] > A[right]) {
				if (target>=A[left] && target<A[mid]) right = mid - 1;
				else left = mid + 1;
			}
			else {
				if (target>A[mid] && target<=A[right]) left = mid + 1;
				else right = mid - 1;	
			}
		}
		return false;
	}
};
*/

class Solution {
public:
	bool search(int A[], int n, int target) {
		if (n <= 0) return false;
	
		int left=0, right=n-1, mid;
		while (left <= right) {
			int mid = left+(right-left)/2;
			if (target == A[mid]) return true;
			if (A[mid] > A[right]) {
				if (target > A[mid]) left = mid + 1;
				else {
					if (target >= A[left]) right = mid - 1;
					else left = mid + 1;
				}
			}
			else if (A[mid] < A[right]) {
				if (target < A[mid]) right = mid - 1;
				else {
					if (target <= A[right]) left = mid + 1;
					else right = mid - 1;
				}
			}
			else right = right - 1;
		}
		return false;
	}
};

int main()
{

}
