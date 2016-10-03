#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

/*
class Solution {
public:
	ListNode *deleteDuplicates(ListNode *head) {
		if (head == NULL) return NULL;
		ListNode *head0 = new ListNode(-1);
		ListNode *cur=head, *pre=head0;

		while (cur != NULL) {
			ListNode *p = cur->next;
			while (p!=NULL && p->val==cur->val) {
				p = p->next;
			}
			if (cur->next == p) {
				pre->next = cur;
				pre = pre->next;
			}
			cur = p;
		}
		pre->next = NULL;
		return head0->next;
	}
};
*/

class Solution {
public:
	ListNode *deleteDuplicates(ListNode *head) {
		if (head == NULL) return NULL;
		ListNode *head0 = new ListNode(-1);
		ListNode *cur=head, *pre=head0;

		while (cur != NULL) {
			bool duplicated = false;
			while (cur->next && cur->val == cur->next->val) {
				duplicated = true;
				cur = cur->next;
			}
			if (!duplicated) {
				pre->next = cur;
				pre = pre->next;
			}
			cur = cur->next;	
		}
		pre->next = NULL;
		return head0->next;
	}
};


void print(ListNode *head)
{
	while (head != NULL) {
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
}

int main()
{
	ListNode *head = new ListNode(1);
	//head->next = new ListNode(1);
	//head->next->next = new ListNode(2);
	//head->next->next->next = new ListNode(2);

	Solution s;
	head = s.deleteDuplicates(head);
	print(head);
}
