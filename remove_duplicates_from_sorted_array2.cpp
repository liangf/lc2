#include <iostream>
using namespace std;
/*
// remove all the duplicated elements
class Solution {
public:
	int removeDuplicates(int A[], int n) {
		if (n == 0) return 0;

		int pre = -1, cur = 0;
		while (cur < n) {
			int p = cur;
			while (p+1<n && A[cur]==A[p+1]) ++p;
			if (cur == p) A[++pre] = A[cur];
			cur = p + 1;
		}
		return pre+1;
	}
};
*/

class Solution {
	int removeDuplicates(int A[], int n) { 
		if (n == 0) return 0;
		int cur = 0, next = 1, count = 1;	

		while (next < n) {
			if (A[cur] == A[next]) {
				if (count == 1) A[++cur] = A[next];
				++next;
				++count;
			}
			else {
				++cur;
				A[cur] = A[next];	
				++next;
				count = 1;
			}
		}
		return cur + 1;
	}
};

int main()
{

}
