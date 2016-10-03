#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	bool isPalindrome(string s) {
		int left = 0, right = s.length();
		while (left < right) {
			if ( !isAlphaNum(s[left]) ) {
				++left;
				continue;
			}
			if ( !isAlphaNum(s[right]) ) {
				--right;
				continue;
			}		
			if (tolower(s[left]) != tolower(s[right])) return false;
			++left; 
			--right;
		}
		return true;
	}
	bool isAlphaNum(char c) {
		if ((c>='a'&&c<='z') || (c>='A'&&c<='Z') || (c>='0'&&c<='9')) return true;
		return false;
	}
};

int main()
{
	string s = "A man, a plan, a canal: Panama";
	s = "1a2";
	Solution S;
	cout << S.isPalindrome(s) << endl;
}
