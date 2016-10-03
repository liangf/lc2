#include <iostream>
using namespace std;

class Solution {
public:
	int removeElement(int A[], int n, int elem) {
		int left=0, right=n-1;
		while (left <= right) {
			if (A[left] == elem) swap(A[left], A[right--]);
			else ++left;
		}
		return right+1;
	}
};

int main()
{

}
