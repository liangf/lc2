#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
	string intToRoman(int num) {
		string s = "";
		unordered_map<int, string> umap;
		unordered_map<int, char> romans;
		romans[1]    = 'I';
		romans[5]    = 'V';
		romans[10]   = 'X';
		romans[50]   = 'L';
		romans[100]  = 'C';
		romans[500]  = 'D';
		romans[1000] = 'M';
		umap[4]      = "IV";
		umap[9]      = "IX";
		umap[40]     = "XL";
		umap[90]     = "XC";
		umap[400]    = "CD";
		umap[900]    = "CM";
		while (num > 0) {
			int base=0, n=0;
			if 		(num >= 1000) 	base = 1000;
			else if (num >= 100) 	base = 100;
			else if (num >= 10) 	base = 10;
			else if (num >= 1) 		base = 1;
			
			n = num / base; 
			if (n==4 || n==9) {
				s += umap[n*base];
				num = num % base;
			}
			else if (n < 5) {
				s += string(n, romans[base]);
				num = num % base;
			}
			else {
				s.push_back(romans[5*base]);
				num = num - 5*base;
			}
		}
		return s;
	}
};

int main()
{
	Solution s;
	for (int i=1; i<20; ++i) cout << s.intToRoman(i) << endl;	
}
