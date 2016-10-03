#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
class Solution {
public:
	TreeNode *sortedListToBST(ListNode *head) {
		int len = 0;
		ListNode *p = head;
		while (p != NULL) {
			p = p->next;
			++len;
		}
		return insert(head, 0, len-1);
	}
	TreeNode *insert(ListNode *head, int left, int right) {
		if (left > right) return NULL;
		int mid = left + (right-left)/2;
		ListNode *midNode=head;
		int count = 0;
		while (count < mid) {
			++count;
			midNode = midNode->next;	
		}
		TreeNode *root = new TreeNode(midNode->val);
		root->left = insert(head, left, mid-1);
		root->right = insert(head, mid+1, right);
		return root; 
	}
};
*/

/*
class Solution {
public:
	TreeNode *sortedListToBST(ListNode *head) {
		if (head == NULL) return NULL;
		ListNode *dummy = new ListNode(-1);
		ListNode *slow=head, *fast=head, *pre=dummy;
		dummy->next = head;
		while (fast->next && fast->next->next) {
			pre = slow;
			slow = slow->next;
			fast = fast->next->next;
		}
		pre->next = NULL;
		TreeNode *root = new TreeNode(slow->val);
		root->left = sortedListToBST(dummy->next);
		root->right = sortedListToBST(slow->next);		
		return root;
	}
};
*/

class Solution {
public:
	TreeNode *sortedListToBST(ListNode *head) {
		int len = 0;
		ListNode *p = head;
		while (p != NULL) {
			p = p->next;
			++len;
		}
		return insert(head, 0, len-1);
	};
	TreeNode *insert(ListNode *midNode, int left, int right) {
		if (left > right) return NULL;
		int mid = left + (right-left)/2;
		
		TreeNode *root = new TreeNode(midNode->val);
		root->left = insert(head, midNode, left, mid-1);
		root->right = insert(head, midNode->next, mid+1, right);
		return root;
	}
};

void print(TreeNode *root)
{
	if (root == NULL) return;

	print(root->left);
	cout << root->val << endl;
	print(root->right);
}

int main()
{
	ListNode *head = new ListNode(1);
	head->next = new ListNode(3);
	head->next->next = new ListNode(8);
	
	Solution s;
	TreeNode *root = s.sortedListToBST(head);
	print(root);	
}
