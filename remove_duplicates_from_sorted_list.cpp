#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *deleteDuplicates(ListNode *head) {
		if (head == NULL) return head;	
		ListNode *p = head;
		while (p->next != NULL) {
			if (p->val == p->next->val) {
				p->next = p->next->next;
			}
			else p = p->next;
		}
		return head;
	}
};

void print(ListNode *head)
{
	while (head) {
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
}

int main()
{
	ListNode *head = new ListNode(1);
	head->next = new ListNode(1);
	head->next = new ListNode(1);
	head->next = new ListNode(2);

	Solution s;
	head = s.deleteDuplicates(head);
	print(head);
}
