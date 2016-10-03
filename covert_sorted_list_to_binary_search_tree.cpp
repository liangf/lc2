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

class Solution {
public:
	TreeNode *sortedListToBST(ListNode *head) {
		
	}
};
/*
class Solution {
public:
	TreeNode *sortedListToBST(ListNode *head) {
		ListNode *slow=head, *fast=head;
		while (fast->next && fast->next->next) {
			slow = slow->next;
			fast = fast->next->next;
		}
		ListNode *head2 = fast->next;
		fast->next = NULL;
	}
};
*/

int main()
{

}
