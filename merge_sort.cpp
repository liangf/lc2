#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> &nums)
{
	for (int i=0; i<nums.size(); ++i) {
		cout << nums[i] << " ";
	}
	cout << endl;
}

vector<int> merge(vector<int> &L, vector<int> &R)
{
	if (L.size() == 0) return R;
	if (R.size() == 0) return L;
	vector<int> result(L.size()+R.size(), 0);

	int i=0, j=0, k=0;
	while (i<L.size() && j<L.size()) {
		if (L[i] < R[j]) {
			result[k] = L[i];
			++i;		
		}
		else {
			result[k] = R[j];
			++j;
		}
		++k;	
	}
	for (; i<L.size(); ++i) result[k++] = L[i];
	for (; j<R.size(); ++j) result[k++] = R[j];	
	return result;
}

vector<int> divide(vector<int> &nums, int left, int right)
{
	if (left == right) return vector<int>(1, nums[left]);

	int mid = left+(right-left)/2;
	vector<int> L = divide(nums, left, mid);
	vector<int> R = divide(nums, mid+1, right);
	return merge(L, R);
}


void merge(vector<int> &nums, int left, int mid, int right, vector<int> &num2)
{
	int i=left, j=mid+1, k=left;
	while (i<=mid && j<=right) {
		if (nums[i] < nums[j]) {
			num2[k] = nums[i];
			++i;
		}
		else {
			num2[k] = nums[j];
			++j;
		}
		++k;
	}
	for (; i<=mid; ++i) num2[k++] = nums[i];
	for (; j<=right; ++j) num2[k++] = nums[j]; 
}

void copy(vector<int> &src, int left, int right, vector<int> &des)
{
	for (int i=left; i<=right; ++i) {
		des[i] = src[i];
	}
}

void divide(vector<int> &nums, int left, int right, vector<int> &num2)
{
	if (left == right) return;

	int mid = left + (right-left)/2;
	divide(nums, left, mid, num2);
	divide(nums, mid+1, right, num2);
	merge(nums, left, mid, right, num2);
	copy(num2, left, right, nums);
}

vector<int> mergeSort(vector<int> &nums) 
{
	return divide(nums, 0, nums.size()-1);
}

int main()
{
	vector<int> nums;
	nums.push_back(3);
	nums.push_back(1);
	nums.push_back(4);
	nums.push_back(2);
	nums.push_back(2);
		
	vector<int> num2(nums.size(), 0);	
	
	print(nums);
	//vector<int> result = mergeSort(nums);
	divide(nums, 0, nums.size()-1, num2);
	print(nums);
}
