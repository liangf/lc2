#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *partition(ListNode *head, int x) {
		ListNode *L = new ListNode(-1);
		ListNode *R = new ListNode(-1);
		ListNode *preL=L, *preR=R;

		while (head != NULL) {
			if (head->val < x) {
				preL->next = head;
				preL = preL->next;
			}
			else {
				preR->next = head;
				preR = preR->next;
			}
			head = head->next;
		}
		preR->next = NULL;
		if (preL == NULL) return R->next;
		preL->next = R->next;
		return L->next;
	}
};

int main()
{

}
