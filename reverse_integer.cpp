#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
	int reverse(int x) {
		int sum = 0;
		while (x != 0) {
			if (sum>INT_MAX/10 || (sum==INT_MAX/10&&x%10>=7)) {
				return INT_MAX;
			}
			if (sum<INT_MIN/10 || (sum==INT_MIN/10&&x%10<-7)) {
				return INT_MIN;
			}
			sum = sum*10 + x%10;
			x = x/10;
		}
		return sum;
	}
};

int main()
{
	Solution s;
	//cout << s.reverse(1234567892) << endl;
	//cout << s.reverse(-123456789) << endl;
	cout << s.reverse(-1234567892) << endl;
}
