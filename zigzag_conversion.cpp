#include <iostream>
using namespace std;

class Solution {
public:
	string convert(string s, int nRows) {
		string result = "";
		for (int i=0; i<nRows; ++i) {
			for (int j=i; j<s.length(); j+=2*nRows-2) {
				result.push_back(s[j]);	
				if (i!=0 && i!=nRows-1 && j+2*nRows-2-2*i<s.length()) {
					result.push_back(s[j+2*nRows-2-2*i]);
				}
			}
		}
		return result;
	}
};

int main()
{

}
