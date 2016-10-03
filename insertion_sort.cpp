#include <iostream>
#include <vector>
using namespace std;
/*
void insertionSort(vector<int> &nums)
{
	for (int i=1; i<nums.size(); ++i) {
		int tmp = nums[i];
		int j = 0;
		for (; j<i; ++j) {
			if (nums[j] > nums[i]) break;
		}
		// move the a[j] a[j+1] ... a[i-1] back
		for (int k=i; k>j; --k) {
			nums[k] = nums[k-1];
		}
		nums[j] = tmp;
	}
}
*/

void insertionSort(vector<int> &nums)
{	
	for (int i=1; i<nums.size(); ++i) {
		int tmp = nums[i];
		int j = i;
		while (j>0 && nums[j-1]>tmp) {
			nums[j] = nums[j-1];
			--j;
		}
		nums[j] = tmp;
	}
}
void print(vector<int> &nums) 
{
	for (int i=0; i<nums.size(); ++i) {
		cout << nums[i] << " ";
	}
	cout << endl;
}

int main()
{
	vector<int> nums;
	nums.push_back(3);
	nums.push_back(2);
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(2);

	
	print(nums);
	insertionSort(nums);
	print(nums);
}
