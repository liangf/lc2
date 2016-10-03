#include <iostream>
#include <string>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
	string multiply(string num1, string num2) {
		string result="", base="";	
		if (num1.size() < num2.size()) swap(num1, num2);
		for (int i=num2.size()-1; i>=0; --i) {
			string ri = multiply(num1, num2[i]-'0');
			ri = ri + base;
			result = add(ri, result);
			base.push_back('0');
		}
		return result;
	}
	string multiply(string num, int n) {
		string result = "0";
		for (int i=0; i<n; ++i) result = add(result, num);
		return result;
	}
	string add(string num1, string num2) {
		string result = "";
		int carry=0, sum = 0, i=num1.size()-1, j = num2.size()-1;
		while (i>=0 || j>=0) {
			int si = i>=0 ? num1[i]-'0' : 0;
			int sj = j>=0 ? num2[j]-'0' : 0;
			sum = (si+sj+carry)>9 ? (si+sj+carry)%10 : (si+sj+carry);
			carry = (si+sj+carry)/10;
			result.push_back(sum+'0');
			--i; --j;
		}
		if (carry > 0) result.push_back(carry+'0');
		reverse(result.begin(), result.end());
		return result;
	}
};

int main()
{
	string num1 = "0";
	string num2 = "0";
	Solution s;
	cout << s.multiply(num1, num2);
	//cout << s.add(num1, num2) << endl;
	//cout << s.multiply(num1, 2) << endl;
}
