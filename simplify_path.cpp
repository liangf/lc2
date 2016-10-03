#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
	string simplifyPath(string path) {
		vector<string> vec;
		string result = "";

		int i = path.find('/');
		if (i == string::npos) i = path.length();
		while (i < path.length()) {
			int j = path.find('/', i+1);
			if (j == string::npos) j = path.length();
			if (j-i > 1) {
				string s = path.substr(i+1, j-i-1);
				if (s!="." && s!= "..") vec.push_back(s);
				else if (s==".." && !vec.empty()) vec.pop_back();
			}
			i = j;
		}
		for (int i=0; i<vec.size(); ++i) result += "/" + vec[i];
		return result == "" ? "/" : result;
	}
};

int main()
{
	//string s = "/home/";
	//string s = "/../";
	//string s = "/a/./b/../../c/";
	//string s = "/a/./b//../../c/";
	string s = "/home/foo/.ssh/../.ssh2/authorized_keys/";	

	Solution S;
	cout << S.simplifyPath(s) << endl;
}
