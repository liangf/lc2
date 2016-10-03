#include <iostream>
#include <queue>
using namespace std;

struct TreeLinkNode {
	int val;	
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

/*
// method 1
class Solution {
public:
	void connect(TreeLinkNode *root) {
		TreeLinkNode *curLevHead=root, *nextLevHead;		
		while (curLevHead != NULL) {
			nextLevHead = NULL;
			TreeLinkNode *head = new TreeLinkNode(-1);
			TreeLinkNode *to_delete = head;
			while (curLevHead != NULL) {
				if (nextLevHead == NULL) {
					if (curLevHead->left) nextLevHead = curLevHead->left;
					else if (curLevHead->right) nextLevHead = curLevHead->right;
				}		
				if (curLevHead->left) {
					head->next = curLevHead->left;
					head = head->next;
				}
				if (curLevHead->right) {
					head->next = curLevHead->right;
					head = head->next;
				}
				curLevHead = curLevHead->next;
			}
			delete to_delete;
			curLevHead = nextLevHead;	
		}
	}
};
*/

class Solution {
public:
	void connect(TreeLinkNode *root) {
		if (root == NULL) return;
		queue<TreeLinkNode*> cur;
		cur.push(root);

		while ( !cur.empty() ) {
			queue<TreeLinkNode*> next;
			TreeLinkNode *head = new TreeLinkNode(-1);
			TreeLinkNode *to_delete = head;
			while ( !cur.empty() ) {
				TreeLinkNode *n = cur.front();
				cur.pop();
				if (n->left) {
					next.push(n->left);
					head->next = n->left;
					head = head->next;
				}
				if (n->right) {
					next.push(n->right);
					head->next = n->right;
					head = head->next;
				}
			}
			delete to_delete;
			cur = next;
		}
	}
};

void print(TreeLinkNode *root)
{
	TreeLinkNode *cur=root, *next;
	while (cur != NULL) {
		next = NULL;
		while (cur != NULL) {
			cout << cur->val << " ";
			if (next == NULL) {
				if (cur->left) next = cur->left;
				else if (cur->right) next = cur->right;
			}
			cur = cur->next;
		}
		cout << endl;
		cur = next;
	}
}

int main()
{
	TreeLinkNode *root = new TreeLinkNode(1);
	root->left = new TreeLinkNode(2);
	root->right = new TreeLinkNode(3);

	Solution s;
	s.connect(root);	
	print(root);
}
