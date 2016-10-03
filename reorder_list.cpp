#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

void print(ListNode *head)
{
	while (head) {
		cout << head->val << endl;
		head = head->next;
	}
}

/*
class Solution {
public:
	void reorderList(ListNode *head) {
		if (head == NULL) return;
		vector<ListNode *> vec;
		for (; head!=NULL; head=head->next) {
			vec.push_back(head);
		}
		int n = vec.size();
		head = vec[0];
		ListNode *pre = NULL;
		for (int i=0; i<n/2; ++i) {
			if (pre) pre->next = vec[i];
			vec[i]->next = vec[n-1-i];
			pre = vec[i]->next;
		}
		if(pre) {
			if (n % 2 == 1) {
				pre->next = vec[n/2];
				pre->next->next = NULL;
			}
			else pre->next = NULL;
		}
	}
};
*/

/*
class Solution {
public:
	void reorderList(ListNode *head) {
		if (head==NULL || head->next==NULL) return;
		int n = 0, count = 0;

		for (ListNode *p=head; p!=NULL; p=p->next) ++n;
		ListNode *p = head;
		while (p && count<(n-1)/2) {
			++count;
			p = p->next;
		}	
		ListNode *head2 = p->next;
		p->next = NULL;
		head2 = reverse(head2);
		p = head;
		while (head && head2) {
			ListNode *next = p->next;
			ListNode *next2 = head2->next;
			p->next = head2;
			head2->next = next;
			p = next;			
			head2 = next2;
		}
	}
	ListNode *reverse(ListNode *head) {
		ListNode *dummy = new ListNode(-1);
		while (head != NULL) {
			ListNode *next = head->next;
			head->next = dummy->next;
			dummy->next = head;
			head = next;
		}
		return dummy->next;
	}
};
*/


class Solution {
public:
	void reorderList(ListNode *head) {
		if (head==NULL || head->next==NULL) return;
		ListNode *slow=head, *fast=head;
		while (fast->next && fast->next->next) {
			slow = slow->next;
			fast = fast->next->next;
		}
		ListNode *head2 = slow->next;
		slow->next = NULL;
		head2 = reverse(head2);
		ListNode *p = head;
		while (head2 != NULL) {
			ListNode *next2 = head2->next;
			head2->next = p->next;
			p->next = head2;
			p = head2->next;			
			head2 = next2;
		}
	}
	ListNode *reverse(ListNode *head) {
		if (head==NULL || head->next==NULL) return head;

		ListNode *last = reverse(head->next);
		ListNode *second = head->next;
		second->next = head;
		head->next = NULL;
		return last;
	}
};


int main()
{
	ListNode *head = new ListNode(1);
	ListNode *n2 = new ListNode(2);
	ListNode *n3 = new ListNode(3);
	ListNode *n4 = new ListNode(4);
	head->next = n2;
	n2->next = n3;	
	//n3->next = n4;	
	print(head);

	//Solution s;
	//s.reorderList(head);
	//print(head);
}
