#include <iostream>
#include <vector>
using namespace std;
/*
class Solution {
public:
	vector<int> searchRange(int A[], int n, int target) {
		vector<int> result(2, -1);
		if (n <= 0) return result;

		int left=0, right=n-1, low=-1, high=-1;
		while (left <= right) {
			int mid = left + (right-left)/2;
			if (target > A[mid]) left = mid + 1;
			else right = mid - 1;
		}
		low = left;
		left = 0; right = n-1;
		while (left <= right) {
			int mid = left + (right-left)/2;
			if (target >= A[mid]) left = mid + 1;
			else right = mid - 1;
		}
		high = right;
		if (low <= high) {
			result[0] = low;
			result[1] = high;
		}
		return result;
	}	
};
*/

class Solution {
public:
	vector<int> searchRange(int A[], int n, int target) {
		vector<int> result(2, -1);
		if (n <= 0) return result;

		result[0] = findLowerBound(A, n, target);
		result[1] = findUpperBound(A, n, target);
		return result;
	}
	int findLowerBound(int A[], int n, int target) {
		int left=0, right=n-1;
		while (left <= right) {
			if (left == right) {
				if (A[left] == target) return left;
				else return -1;
			}
			int mid = left + (right-left)/2;
			if (target <= A[mid]) right = mid;
			else left = mid + 1;
		}
		return -1;
	}
	int findUpperBound(int A[], int n, int target) {
		int left=0, right=n-1;
		while (left <= right) {
			if (left == right) {
				if (A[left] == target) return left;
				else return -1;
			}
			int mid = left + (right-left+1)/2;
			if (target < A[mid]) right = mid - 1;
			else left = mid;
		}
		return -1;
	}
};


int main()
{

}
