#include <iostream>
#include <cstring>
using namespace std;

class Solution {
public:
	int lengthOfLastWord(const char *s) {
		if (strlen(s) == 0) return 0;
		int len = strlen(s);
		int i = len - 1;

		for (; i>=0; --i) {
			if (s[i] != ' ') break;
		}
		int j = i;
		for (; j>=0; --j) {
			if (s[j] == ' ') break;
		}
		return i - j;
	}
};

int main()
{

}
