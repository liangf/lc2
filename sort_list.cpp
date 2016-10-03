#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *sortList(ListNode *head) {
		int len = 0;
		ListNode *p = head;
		while (p) {
			++len;
			p = p->next;
		}
		return divide(head, len);
	}
	ListNode* divide(ListNode *head, int len) {
		if (len <= 1) return head;

		ListNode *mid = getMiddleOfList(head, len);
		ListNode *mid_next = mid->next;
		mid->next = NULL;
		ListNode *left = divide(head, len/2);
		ListNode *right = divide(mid_next, len-len/2);

		return merge(left, right);
	}
	ListNode* merge(ListNode *L, ListNode *R) {
		if (L == NULL) return R;
		if (R == NULL) return L;

		ListNode *head0 = new ListNode(-1);
		ListNode *p = head0;
		while (L!=NULL && R!=NULL) {
			if (L->val < R->val) {
				p->next = L;
				L = L->next;
			}
			else {
				p->next = R;
				R = R->next;
			}
			p = p->next;
		}
		p->next = (L == NULL) ? R : L;
		return head0->next;
	}
	ListNode* getMiddleOfList(ListNode* head, int len) {
		int count=1;
		while (head!=NULL && count<len/2) {
			++count;
			head = head->next;
		}
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
	ListNode *head = new ListNode(3);
	ListNode *n2= new ListNode(1);
	ListNode *n3 = new ListNode(4);
	ListNode *n4 = new ListNode(2);
	head->next = n2;
	n2->next = n3;
	n3->next = n4;
	
	Solution s;
	//head = s.merge(head, n3);
	head = s.sortList(head);
	print(head);	
}
