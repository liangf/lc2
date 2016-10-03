#include <iostream>
using namespace std;

class Solution {
public:
	int searchInsert(int A[], int n, int target) {
		int left=0, right=n-1;
		
		while (left <= right) {
			int mid = left + (right-left)/2;
			if (target <= A[mid]) right = mid - 1;
			else left = mid + 1;
		}
		return left;
	}
};

int main()
{

}
