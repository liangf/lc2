#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string> &strs) {
		if (strs.size() == 0) return "";
		string result = strs[0];
		for (int i=1; i<strs.size(); ++i) {
			string s = "";
			for (int len=1; len<=strs[i].size(); ++len) {
				string s1 = strs[0].substr(0, len);	
				string s2 = strs[i].substr(0, len);
				if (s1 == s2) s = s1;
				else break;
			}
			if (s.length() < result.length()) result = s;
		}
		return result;
	}
};

int main()
{

}
