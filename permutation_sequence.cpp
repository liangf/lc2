#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
class Solution {
public:
	string getPermutation(int n, int k) {
		string result = "";
		if (n<=0 || k<=0 || k>fact(n)) return result;

		vector<int> num;
		for (int i=0; i<n; ++i) num.push_back(i+1);
		dfs(num, k-1, result);
		return result;
	}
	void dfs(vector<int> &num, int k, string &result) {
		if (k == 0) {
			for (int j=0; j<num.size(); ++j) result.push_back(num[j]+'0');
			return;
		}
		
		int i = k / fact(num.size()-1);
		k = k % fact(num.size()-1);

		result.push_back(num[i]+'0');
		num.erase(num.begin()+i);
		dfs(num, k, result);
	}
	int fact(int n) {
		if (n == 1) return 1;
		return n * fact(n-1);
	}
};
*/

class Solution {
public:
	string getPermutation(int n, int k) {
		string result = "";
		if (n<=0 || k<=0 || k>fact(n)) return result;

		vector<int> num;
		for (int i=0; i<n; ++i) num.push_back(i+1);
		k = k - 1;
		while (k > 0) {
			int i = k / fact(num.size()-1);
			k = k % fact(num.size()-1);
			result.push_back(num[i]+'0');
			num.erase(num.begin()+i);
		}
		for (int i=0; i<num.size(); ++i) result.push_back(num[i]+'0');
		return result;
	}
	int fact(int n) {
		if (n == 1) return 1;
		return n * fact(n-1);
	}
};

int main()
{
	Solution s;
	cout << s.getPermutation(4, 4) << endl;
}
