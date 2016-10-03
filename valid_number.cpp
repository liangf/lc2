#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	bool isNumber(string s) {
		if (s.length() == 0) return false;
		int start = s.find_first_not_of(' ');
		int end = s.find_last_not_of(' ');
		if (start==string::npos || end==string::npos) return false;
		if (s[start]=='-' || s[start]=='+') ++start;

		bool bNum=false, bDot=false, bE=false, bMinus=false, bPlus=false;
		for (int i=start; i<=end; ++i) {
			if (s[i]>='0' && s[i]<='9') {
				bNum = true;
			}
			else if (s[i] == '.') {
				if (bDot || bE) return false;
				if (i==end && !bNum) return false;
				bDot = true;
			}
			else if (s[i] == '-') {
				if (bMinus || !bE) return false;
				if (i == end) return false;
				if (s[i-1]!='e' && s[i-1]!='E') return false;
				bMinus = true;
			}
			else if (s[i] == '+') {
				if (bPlus || !bE) return false;
				if (i == end) return false;
				if (s[i-1]!='e' && s[i-1]!='E') return false;
				bPlus = true;
			}
			else if (s[i]=='E' || s[i]=='e') {
				if (!bNum || bE) return false;
				if (i == end) return false;
				bE = true;
			}
			else return false;
		}
		return true;
	}
};

int main()
{
	//string s = "0";
	//string s = "0.1";
	//string s = "abc";
	//string s = "1 a";
	//string s = "2e10";
	//string s = "0.";
	//string s = "1e.";
	//string s = "-1.";
	//string s = "+.8";
	string s = " 005047e+6";
	//string s = " 7e+";
	//string s = "7e1+2";
	Solution S;
	cout << S.isNumber(s) << endl;
}
