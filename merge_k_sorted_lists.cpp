#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *mergeKLists(vector<ListNode *> &lists) {
		if (lists.size() == 0) return NULL;
		return divide(lists, 0, lists.size()-1);
	}
	ListNode* divide(vector<ListNode*> &lists, int start, int end) {
		if (start == end) return lists[start];

		int mid = start + (end-start)/2;
		ListNode *left = divide(lists, start, mid);
		ListNode *right = divide(lists, mid+1, end);
		return merge(left, right);
	}
	ListNode* merge(ListNode *left, ListNode *right) {
		ListNode *head = new ListNode(-1);
		ListNode *p = head;
		while (left!=NULL && right!=NULL) {
			if (left->val < right->val) {
				p->next = left;
				left = left->next;	
			}
			else {
				p->next = right;
				right = right->next;
			}
			p = p->next;
		}
		p->next = left!=NULL ? left : right;
		return head->next;
	}
};

int main()
{

}
