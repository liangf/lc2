#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
	int largestRectangleArea(vector<int> &height) {
		int maxArea = 0;
		stack<int> stk;

		for (int i=0; i<height.size(); ) {
			if (stk.empty() || height[i]>height[stk.top()]) stk.push(i++);
			else {
				int cur = stk.top();
				stk.pop();
				int pre = stk.empty() ? -1 : stk.top();
				maxArea = max(maxArea, (i-pre-1)*height[cur]);	
			}
		}
		int i = stk.empty() ? 0 : stk.top()+1;
		while ( !stk.empty() ) {
			int cur = stk.top();
			stk.pop();
			int pre = stk.empty() ? -1 : stk.top();
			maxArea = max(maxArea, (i-pre-1)*height[cur]);	
		}
		return maxArea;
	}
};

int main()
{
	vector<int> height;
	height.push_back(2);
	height.push_back(1);
	height.push_back(2);

	Solution s;
	cout << s.largestRectangleArea(height) << endl;
}
