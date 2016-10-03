#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	string addBinary(string a, string b) {
		string result = "";
		int carry = 0;	
		int i = a.length()-1, j = b.length()-1;
		
		while (i>=0 || j>=0) {
			int si = i>=0 ? a[i]-'0' : 0;
			int sj = j>=0 ? b[j]-'0' : 0;
			int sum = si + sj + carry;
			if (sum > 1) {
				carry = 1;
				sum = sum - 2;
			}
			else carry = 0;
			result.push_back('0'+sum);
			--i; --j;
		}
		if (carry > 0) result.push_back('1');
		reverse(result.begin(), result.end());
		return result;
	}
};

int main()
{
	Solution s;
	cout << s.addBinary("11", "1");
}
