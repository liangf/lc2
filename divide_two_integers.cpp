#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
	int divide(int dividend, int divisor) {
		if (divisor == 0) return INT_MAX;
		if (dividend==INT_MIN && divisor==-1) return INT_MAX;

		long long result = 0;
		long long num = abs((long long)dividend), d = abs((long long)divisor);
		while (d <= num) {
			long long shift=0;
			long long base = d;
			while (base<<1 <= num) {
				base = base<<1;
				++shift;
//cout << "base:" << base << " " << "shift:" << shift << endl;
			}
			num = num - base;
			result = result + (1<<shift);
		}
		if ((dividend>0&&divisor>0)||(dividend<0&&divisor<0)) return result;
		return -result;
	}
};

int main()
{
	Solution s;
	//cout << s.divide(2147483647, 1) << endl;
	//cout << s.divide(-1010369383, INT_MIN) << endl;
	//cout << s.divide(-1, 1) << endl;
	cout << s.divide(INT_MIN, -1) << endl;
	
	cout << (1<<31) << endl;
}
