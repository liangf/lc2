#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<int> plusOne(vector<int> &digits) {
		int carry = 0, sum;
		vector<int> result;
		if (digits.size() == 0) return result;

		for (int i=digits.size()-1; i>=0; --i) {
			if (i == digits.size()-1) sum = digits[i] + 1;
			else sum = digits[i] + carry;
			if (sum > 9) {
				carry = 1;
				sum = sum - 10;
			} 
			else carry = 0;
			result.push_back(sum);
		}
		if (carry > 0) result.push_back(1);
		reverse(result.begin(), result.end());
		return result;
	}
};

int main()
{
	vector<int> digits;
	digits.push_back(1);
	digits.push_back(9);
	Solution s;
	vector<int> res = s.plusOne(digits);
	for (int i=0; i<res.size(); ++i) {
		cout << res[i];
	}
	cout << endl;
}
