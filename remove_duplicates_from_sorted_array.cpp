#include <iostream>
using namespace std;

class Solution {
public:
	int removeDuplicates(int A[], int n) {
		if (n == 0) return 0;
		int cur=0, next=cur+1;
		while (next < n) {
			if (A[cur] == A[next]) ++next;
			else {
				A[cur+1] = A[next];
				++cur;
				++next;
			}
		}
		return cur+1;
	}
};

int main()
{

}
