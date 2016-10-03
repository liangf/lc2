#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		string result = "";
		vector<string> solution;
		if (s.length() == 0) return solution;
		
		dfs(s, 0, 0, result, solution);
	}
	void dfs(string s, int start, int n, string result, vector<string> &solution) {
		if (start >= s.length()) return;
		if (n >= 3) {
			result += s.substr(start);
			if ( isValid(result) ) solution.push_back(result);
			return;
		}

		dfs(s, start+1, n+1, result+s.substr(start, 1)+".", solution);	
		dfs(s, start+2, n+1, result+s.substr(start, 2)+".", solution);	
		dfs(s, start+3, n+1, result+s.substr(start, 3)+".", solution);	
	}
	bool isValid(string s) {
		size_t i = 0;
		while (i < s.length()) {
			size_t j = s.find(".", i);
			if (j == string::npos) j = s.length();
			if (j-i > 3) return false;
			if (atoi(s.substr(i, j-i).c_str())>255) return false;
			if (j-i==2 && atoi(s.substr(i, j-i).c_str())<10) return false;
			if (j-i==3 && atoi(s.substr(i, j-i).c_str())<100) return false;
			i = j+1;
		}
		return true;
	}
};

int main()
{
	//string s = "25525511135";
	//string s = "0000";
	string s = "010010";
	Solution S;
	//s = "25.5.2.5511135";
	//S.isValid(s);

	vector<string> sol = S.restoreIpAddresses(s);
	for (int i=0; i<sol.size(); ++i) {
		cout << sol[i] << endl;
	}
}
