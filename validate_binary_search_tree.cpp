#include <iostream>
#include <climits>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool isValidBST(TreeNode *root) {
		pre = NULL;
		return inorder(root);
	}
	bool inorder(TreeNode *root) {
		if (root == NULL) return true;
		
		bool left = inorder(root->left);
		if (pre!=NULL && pre->val>=root->val) return false;
		pre = root;
		bool right = inorder(root->right);
		return left && right;
	}
private:
	TreeNode* pre;
};

int main()
{
	TreeNode *root = new TreeNode(4);
	//root->left = new TreeNode(2);
	//root->left->left = new TreeNode(1);
	//root->left->right = new TreeNode(3);
	//root->right = new TreeNode(0);
	//root->left = new TreeNode(4);

	Solution s;
	cout << s.isValidBST(root) << endl;
}
