#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0) return false;
		
		int base = 1;
		while (base <= x/10) {
			base = base * 10;
		}
		while (x > 0) {
			if (x%10 != x/base) return false;
			x = x % base;
			x = x/10;
			base = base/100;
		}
		return true;
	}
};

int main()
{
	Solution s;
	//cout << s.isPalindrome(12321);
	//cout << s.isPalindrome(11);
	cout << s.isPalindrome(1874994781);
	//cout << INT_MAX << endl;
}
