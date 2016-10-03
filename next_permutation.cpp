#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	void nextPermutation(vector<int> &num) {
		if (num.size() == 0) return;

		for (int i=num.size()-2; i>=0; --i) {
			if (num[i] < num[i+1]) {
				for (int j=num.size()-1; j>=i; --j) {
					if (num[j] > num[i]) {
						swap(num[i], num[j]);
						break;
					}
				}
				reverse(num.begin()+i+1, num.end());
				return;
			}
		}
		reverse(num.begin(), num.end());
		return;
	}
};

int main()
{

}
