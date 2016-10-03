#include <iostream>
using namespace std;

class Solution {
public:
	int sqrt(int x) {
		long long left=0, right=x, mid;

		while (left <= right) {
			mid = left + (right-left)/2;
			if (mid*mid == x) return mid;
			else if (mid*mid > x) right = mid - 1;
			else left = mid + 1;
		}
		return right;
	}
};

int main()
{
	Solution s;
	cout << s.sqrt(1);
}
