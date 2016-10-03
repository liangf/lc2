#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string countAndSay(int n) {
		string result = "";
		if (n <= 0) return result;
		
		result = "1";
		for (int i=2; i<=n; ++i) {
			int count = 1;
			string newres = "";
			result.push_back('#');
			for (int j=1; j<result.length(); ++j) {
				if (result[j] == result[j-1]) ++count;
				else {
					newres.push_back(count+'0');
					newres.push_back(result[j-1]);	
					count = 1;
				}
			}
			result = newres;
		}
		return result;
	}
};

int main()
{
	Solution s;
	//for (int i=0; i<10; ++i)
	cout << s.countAndSay(6) << endl;
}
