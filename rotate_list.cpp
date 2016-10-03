#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *rotateRight(ListNode *head, int k) {
		if (head == NULL) return NULL;
		int len = 0;
		ListNode *p = head, *end = NULL;

		while (p != NULL) {
			++len;
			end = p;
			p = p->next;
		}
		p = head;
		int count = len - k%len;
		if (cout == 0) return head;

		while (p!=NULL && count>1) {
			--count;
			p = p->next;
		}
		end->next = head;		
		head = p->next;
		p->next = NULL;
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
	head = s.rotateRight(head, 0);	
	print(head);
}
