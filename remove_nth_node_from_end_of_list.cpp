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
	ListNode *removeNthFromEnd(ListNode *head, int n) {
		int count = 1, len = 0;
		ListNode *cur = head;
		while (cur != NULL) {
			++len;
			cur = cur->next;
		}
		if (len==0|| n<1 || n>len) return head;
		if (n == len) return head->next;
		cur = head;
		while (count < len-n) {
			++count;
			cur = cur->next;
		}
		cur->next = cur->next->next;
		return head;
	}
};
*/

/*
class Solution {
public:
	ListNode *removeNthFromEnd(ListNode *head, int n) {
		if (n <= 0) return head;
		int count = 1;
		ListNode *first=head, *second=head;
		while (first!=NULL && count<n) {
			++count;
			first = first->next;
		}
		if (first == NULL) return head;
		first = first->next;
		if (first == NULL) return head->next;
		while (first->next!=NULL) {
			first = first->next;
			second = second->next;
		}	
		second->next = second->next->next;
		return head;
	}
};
*/

class Solution {
public:
	ListNode *removeNthFromEnd(ListNode *head, int n) {
		if (n<=0 || head==NULL) return head;
		ListNode *first=head, *second=head;
		
		while (n>0 && first!=NULL) {
			--n;
			first = first->next;
		}
		if (n > 0) return head;
		if (first == NULL) return head->next;
		while (first->next != NULL) {
			first = first->next;
			second = second->next;
		}
		second->next = second->next->next;
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
	head = s.removeNthFromEnd(head, 5);
	print(head);
}
