#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *reverseBetween(ListNode *head, int m, int n) {
		int count = 1;
		ListNode *pre=NULL, *cur=head, *next, *end;
		while (count < m) {
			pre = cur;
			cur = cur->next;
			++count;
		}
		end = cur;
		ListNode *head0 = new ListNode(-1);
		while (count <= n) {
			next = cur->next;
			cur->next = head0->next;
			head0->next = cur;
			cur = next;
			++count;
		}	
		end->next = cur;
		if (pre == NULL) return head0->next;
		pre->next = head0->next;
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
	ListNode *n2 = new ListNode(2);
	ListNode *n3 = new ListNode(3);
	ListNode *n4 = new ListNode(4);
	ListNode *n5 = new ListNode(5);
	head->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;	
	
	print(head);
	Solution s;
	head = s.reverseBetween(head, 1, 1);
	print(head);
}
