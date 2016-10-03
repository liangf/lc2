#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		ListNode *head0 = new ListNode(-1);;
		ListNode *p = head0;
		int carry = 0;

		while (l1!=NULL || l2!=NULL) {
			int a = l1!=NULL ? l1->val : 0;
			int b = l2!=NULL ? l2->val : 0;
			int sum = a + b + carry;
			carry = sum/10;
			sum = sum%10;
			p->next = new ListNode(sum);		
			l1 = l1!=NULL ? l1->next : NULL;
			l2 = l2!=NULL ? l2->next : NULL;
			p = p->next;
		}
		if (carry > 0) p->next = new ListNode(carry);
		return head0->next;
	}
};

int main()
{

}
