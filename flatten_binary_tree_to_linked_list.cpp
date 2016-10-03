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
	void flatten(TreeNode *root) {
		pre = NULL;
		preOrder(root);
	}
	void preOrder(TreeNode *root) {
		if (root == NULL) return;
		
		TreeNode *right = root->right;
		if (pre != NULL) {
			pre->left = NULL;
			pre->right = root;
		}
		pre = root;
		preOrder(root->left);
		preOrder(right);
	}
private:
	TreeNode *pre;
};

int main()
{

}
