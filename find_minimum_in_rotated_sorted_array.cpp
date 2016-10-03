#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/*
class Solution {
public:
	int findMin(vector<int> &num) {
		if (num.size() == 0) return INT_MIN;

		int left, right, mid;
		left = 0;
		right = num.size() - 1;
	
		while (left <= right) {
			mid = left + (right-left)/2;
			if (num[left]<=num[mid] && num[mid]<=num[right]) return num[left];
			if (num[mid] > num[right]) left = mid + 1;
			else right = mid;

		}	
		return INT_MIN;
	}
};
*/

class Solution {
public:
	int findMin(vector<int> &num) {
		int left=0, right=num.size()-1;
		
		while (left <= right) {
			int mid = left + (right-left)/2;
			if (num[mid] > num[right]) left = mid + 1;
			else {
				if (num[mid] >= num[left]) return num[left];
				else right = mid;
			}
		}
		return -1;
	}
};


int main()
{
	vector<int> num;
	num.push_back(4);
	num.push_back(5);
	num.push_back(6);
	num.push_back(7);
	num.push_back(0);
	num.push_back(1);
	num.push_back(2);
	
	Solution s;
	cout << s.findMin(num) << endl;
}
