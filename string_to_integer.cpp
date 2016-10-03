#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
	int atoi(const char *str) {
		int result = 0;
		bool isPositive = true;
		while (*str == ' ') ++str;
		if (*str=='+' || *str=='-') {
			if (*str++ == '-') isPositive = false;
		}
		while (*str != 0) {
			if (*str>'9' || *str<'0') return isPositive ? result : -result;
			if (result>INT_MAX/10 || result==INT_MAX/10 && *str>='8') {
				return isPositive ? INT_MAX : INT_MIN;
			}
			result = result*10 + *str-'0';
			++str;
		}
		return isPositive ? result : -result;
	}
};

int main()
{
	Solution s;
	//char str[] = "-123456";
	//char str[] = "-2147483647";
	//char str[] = "             -2147483649";
	//char str[] = "  -0012a42";
	char str[] = "      -11919730356x";
	cout << s.atoi(str) << endl;
}
