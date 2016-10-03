#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
	int romanToInt(string s) {
		unordered_map<char, int> romans;
		romans['I'] = 1;
		romans['V'] = 5;
		romans['X'] = 10;
		romans['L'] = 50;
		romans['C'] = 100;
		romans['D'] = 500;
		romans['M'] = 1000;

		int sum = 0;
		for (int i=0; i<int(s.length())-1; ++i) {
			int cur = romans[ s[i] ];
			int next = romans[ s[i+1] ];
			if (cur < next) sum = sum - cur;
			else sum = sum + cur;
		}
		sum += romans[ s[s.length()-1] ];
		return sum;	
	}
};

int main()
{
	Solution S;
	//string s = "CMLXXXIX";
	string s = "CMXCIX";
	cout << S.romanToInt(s) << endl;
}
