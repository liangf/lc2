#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *reverseKGroup(ListNode *head, int k) {
		if (head==NULL || k==0) return head;

		int len = 0;
		ListNode *newHead = new ListNode(-1);
		ListNode *p=head, *head0 = newHead;
		while (p != NULL) {
			++len;
			p = p->next;
		}
		if (k > len) return head;
		p = head;
		while (len >= k) {
			int count = k;
			while (count > 0) {
				ListNode *next_node = p->next;
				p->next = head0->next;
				head0->next =p;
				p = next_node;
				--count;
			}
			head0 = head;
			head = p;
			len -= k;
		}
		head0->next = head;
		return newHead->next;
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
	head = s.reverseKGroup(head, 5);
	print(head);

}
