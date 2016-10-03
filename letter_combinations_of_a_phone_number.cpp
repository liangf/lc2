#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	vector<string> letterCombinations(string digits) {
		vector<string> num(10, "");
		num[0] = " ";
		num[1] = "";
		num[2] = "abc";
		num[3] = "def";
		num[4] = "ghi";
		num[5] = "jkl";
		num[6] = "mno";
		num[7] = "pqrs";
		num[8] = "tuv";
		num[9] = "wxyz";
		
		string s = "";
		vector<string> result;	
		dfs(digits, num, s, 0, result);
		return result;
	}
	void dfs(string digits, vector<string> &num, string s, int start,
				vector<string> &result) {
		if (start == digits.size()) {
			result.push_back(s);
			return;
		}
		int a = digits[start]-'0';
		for (int i=0; i<num[a].size(); ++i) {
			s.push_back(num[a][i]);
			dfs(digits, num, s, start+1, result);
			s.pop_back();
		}
	}
};

int main()
{
	Solution s;
	vector<string> res = s.letterCombinations("23");
	for (int i=0; i<res.size(); ++i) {
		cout << res[i] << endl;
	}
}
