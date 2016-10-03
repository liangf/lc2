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
	bool hasCycle(ListNode *head) {
		ListNode *slow, *fast;
		slow = fast = head;

		while (fast && fast->next) {
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast) return true;
		}
		return false;
	}
};
*/

class Solution {
public:
	bool hasCycle(ListNode *head) {
		if (head==NULL || head->next==NULL) return false;

		ListNode *slow = head->next;
		ListNode *fast = head->next->next;
		while (fast && fast->next) {
			if (slow == fast) return true;
			slow = slow->next;
			fast = fast->next->next;
		}
		return false;
	}
};

int main()
{
	ListNode *head = new ListNode(1);
	//ListNode *n2 = new ListNode(2);
	//ListNode *n3 = new ListNode(3);
	head->next = head;

	Solution s;
	cout << s.hasCycle(head) << endl;
}
