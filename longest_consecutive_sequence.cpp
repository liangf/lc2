#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
	int longestConsecutive(vector<int> &num) {
		unordered_set<int> uset;
		for (int i=0; i<num.size(); ++i) uset.insert(num[i]);

		int count=0, longest = 0;
		while ( !uset.empty() ) {
			auto it = uset.begin();
			int cur = *it;
			int i = cur-1;
			count = 1;
			uset.erase(cur);
			while (uset.find(i) != uset.end()) {
				uset.erase(i--);
				++count;
			}	
			i = cur + 1;
			while (uset.find(i) != uset.end()) {
				uset.erase(i++);
				++count;
			}
			longest = max(longest, count);
		}
		return longest;
	}
};

int main()
{
	vector<int> num;
	num.push_back(100);
	num.push_back(4);
	num.push_back(200);
	num.push_back(1);
	num.push_back(3);
	num.push_back(2);

	Solution s;
	cout << s.longestConsecutive(num) << endl;
}
