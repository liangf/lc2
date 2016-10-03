#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		if (head==NULL || head->next==NULL) return false;

		ListNode *slow = head->next;
		ListNode *fast = head->next->next;
		while (fast && fast->next) {
			if (slow == fast) break;
			slow = slow->next;
			fast = fast->next->next;
		}
		if (fast==NULL || fast->next==NULL) return NULL;
		slow = head;
		while (slow && fast && slow!=fast) {
			slow = slow->next;
			fast = fast->next;
		}
		return slow;
	}
};

int main()
{
	ListNode *head = new ListNode(1);
	ListNode *n2 = new ListNode(2);
	ListNode *n3 = new ListNode(3);
	head->next = n2;
	n2->next = n3;
	n3->next = head;
	
	Solution s;
	cout << s.detectCycle(head)->val << endl;
}
