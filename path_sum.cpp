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
	bool hasPathSum(TreeNode *root, int sum) {
		if (root==NULL) return false;
		if (root->left==NULL && root->right==NULL) return sum==root->val;

		return hasPathSum(root->left, sum-root->val) || 
				hasPathSum(root->right, sum-root->val);
	}
};

int main()
{
	TreeNode *root = new TreeNode(1);
	root->right = new TreeNode(2);

	Solution s;
	cout << s.hasPathSum(root, 1);
}