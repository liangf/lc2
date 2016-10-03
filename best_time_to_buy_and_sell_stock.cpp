#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int> &prices) {
		int result = 0, minPrice = INT_MAX; 
		for (int i=0; i<prices.size(); ++i) {
			minPrice = min(minPrice, prices[i]);
			result = max(result, prices[i]-minPrice);
		}
		return result;
	}
};

int main()
{
	vector<int> price;
	price.push_back(1);
	price.push_back(3);
	price.push_back(2);
	price.push_back(5);
	//price.push_back(3);
	//price.push_back(4);
	//price.push_back(1);

	Solution s;
	cout << s.maxProfit(price) << endl;
}
