#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool isBalanced(TreeNode *root) {
		return dfs(root)>=0;
	}
	int dfs(TreeNode *root) {
		if (root == NULL) return 0;

		int left = dfs(root->left);
		int right = dfs(root->right);

		if (left==-1 || right==-1) return -1;
		if (abs(left-right) > 1) return -1;
		
		return max(left, right) + 1;
	}
};

int main()
{

}
