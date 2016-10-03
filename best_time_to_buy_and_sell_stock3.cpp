#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int> &prices) {
		if (prices.size() == 0) return 0;
		vector<int> l2r(prices.size(), 0);
		vector<int> r2l(prices.size(), 0);
		int minPrice = INT_MAX, maxPrice = INT_MIN, result = INT_MIN;

		for (int i=0; i<prices.size(); ++i) {
			minPrice = min(minPrice, prices[i]);			
			l2r[i] = prices[i]-minPrice;
			if (i > 0) l2r[i] = max(l2r[i], l2r[i-1]);
		}
		for (int i=prices.size()-1; i>=0; i--) {
			maxPrice = max(maxPrice, prices[i]);
			r2l[i] = maxPrice-prices[i];
			if (i<prices.size()-1) r2l[i] = max(r2l[i], r2l[i+1]);
		}
		for (int i=0; i<prices.size(); ++i) {
			result = max(result, l2r[i]+r2l[i]);
		}
		return result;
	}
};

int main()
{
	vector<int> prices;
	prices.push_back(0);
	//prices.push_back(1);
	//prices.push_back(0);
	//prices.push_back(2);
	//prices.push_back(0);
	//prices.push_back(3);
	
	Solution s;
	cout << s.maxProfit(prices);
}
