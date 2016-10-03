#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *swapPairs(ListNode *head) {
		if (head==NULL || head->next==NULL) return head;
		ListNode *cur=head, *pre=NULL;
		head = cur->next;
		while (cur!=NULL && cur->next!=NULL) {
			ListNode *next = cur->next;
			cur->next = next->next;
			next->next = cur;	
			if (pre != NULL) pre->next = next;
			pre = cur;
			cur = cur->next;
		}
		return head;
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
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);

	print(head);
	Solution s;
	head = s.swapPairs(head);
	print(head);
}
