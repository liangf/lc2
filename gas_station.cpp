#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
		int sum = 0, total = 0, index = 0;

		for (int i=0; i<gas.size(); ++i) {
			int diff = gas[i] - cost[i];
			sum += 	diff;
			total += diff;
			if (sum < 0) {
				index = i + 1;
				sum = 0;
			}
		}	
		return total >=0 ? index : -1;
	}
};

int main()
{

}
