#include <iostream>
#include <climits>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *insertionSortList(ListNode *head) {
		if (head == NULL) return NULL;
		ListNode *head0 = new ListNode(INT_MIN);

		ListNode *cur = head;
		while (cur != NULL) {
			ListNode *next_node = cur->next;
			ListNode *pre = head0;
			while (pre->next!=NULL && pre->next->val<=cur->val) {
				pre = pre->next;
			}
			cur->next = pre->next;
			pre->next = cur;
			cur = next_node;
		}	
		return head0->next;
	}
};

void print(ListNode *head)
{
	while (head) {
		cout << head->val << endl;
		head = head->next;
	}
}

int main()
{
	ListNode *head= new ListNode(3);
	head->next = new ListNode(2);
	head->next->next = new ListNode(2);
	
	print(head);

	Solution s;
	head = s.insertionSortList(head);
	print(head);

}
