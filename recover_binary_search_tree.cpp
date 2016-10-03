#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	void recoverTree(TreeNode *root) {
		pre = p = q = NULL;

		inorder(root);
		int tmp = p->val;
		p->val = q->val;
		q->val = tmp;	
	}
	void inorder(TreeNode *root) {
		if (root == NULL) return;	
		
		inorder(root->left);
		if (pre!=NULL && pre->val>root->val) {
			if (p == NULL) {
				p = pre;
				q = root;
			}
			else q = root;
		}	
		pre = root;
		inorder(root->right);	
	}
private:
	TreeNode *p, *q, *pre;
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
	TreeNode *root = new TreeNode(4); 
	root->left = new TreeNode(2);
	root->left->left = new TreeNode(1);
	root->left->right = new TreeNode(3);
	root->right = new TreeNode(7);
	root->right->left = new TreeNode(5);
	root->right->right = new TreeNode(6);

	print(root);
	cout << endl;
	Solution s;
	s.recoverTree(root);
	print(root);
}
