#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int> &prices) {
		prices.push_back(INT_MIN);
		int result = 0, minPrice = INT_MAX;

		for (int i=0; i<prices.size()-1; ++i) {
			minPrice = min(minPrice, prices[i]);
			if (prices[i] > prices[i+1]) {
				result += prices[i]-minPrice;
				minPrice = prices[i];
			}
		}
		return result;
	}
};

int main()
{
	vector<int> prices;
	prices.push_back(1);
	prices.push_back(4);
	prices.push_back(2);

	Solution s;
	cout << s.maxProfit(prices);
}
