#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	void reverseWords(string &s) {
		trim(s);
		if (s.length() <= 1) return;

		for (int i=0; i<(int)s.length()-1; ) {
			if (s[i]==' ' && s[i+1]==' ') {
				s.erase(s.begin()+i);
			}
			else ++i;
		}
		reverse(s.begin(), s.end());
		int pre, cur=-1, N = s.length();
		while (cur < (int)s.length()) {
			pre = cur+1;	
			cur = s.find(' ', pre);
			if (cur == string::npos) cur = s.length();
			reverse(s.begin()+pre, s.begin()+cur);	
		}
	}
	void trim(string &s) {
		if (s.length() == 0) return;
		int start = s.find_first_not_of(' ');
		int end = s.find_last_not_of(' ');
		if (start==string::npos || end==string::npos) s.clear();
		else s = s.substr(start, end-start+1);
	}
};

int main()
{
	//string s = "the sky is blue";
	//string s = "  the sky is blue ";
	string s = "  the  sky  is blue ";
	//string s = " a";
	Solution S;
	//S.trim(s);
	S.reverseWords(s);
	cout << "[" << s << "]" << endl;
}

