#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int findMin(vector<int> &num) {
		int left=0, right=num.size()-1;

		while (left <= right) {
			if (left == right) return num[left];
			int mid = left + (right-left)/2;
			if (num[mid] > num[right]) left = mid + 1;
			else if (num[mid] < num[right]) {
				if (num[mid] >= num[left]) return num[left];
				else right = mid;
			}
			else --right;
		}
		return -1;
	}
};

int main()
{

}
