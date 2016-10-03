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
	int minDepth(TreeNode *root) {
		if (root == NULL) return 0;
		return dfs(root);
	}
	int dfs(TreeNode *root) {
		if (root->left==NULL && root->right==NULL) return 1;
		
		int left=INT_MAX, right=INT_MAX;	
		if (root->left) left = dfs(root->left)+1;
		if (root->right) right = dfs(root->right)+1;
		return min(left, right);
	}
};

int main()
{

}
