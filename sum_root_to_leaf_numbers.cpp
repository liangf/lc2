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
	int sumNumbers(TreeNode *root) {
		if (root == NULL) return 0;
		int sum, total;
		sum = total = 0;
		dfs(root, sum, total);
		return total;
	}
	void dfs(TreeNode *root, int sum, int &total) {
		if (root->left==NULL && root->right==NULL) {
			sum = sum*10 + root->val;
			total += sum;
			return;
		}
		if(root->left) dfs(root->left, 10*sum+root->val, total);
		if(root->right) dfs(root->right, 10*sum+root->val, total);
	}
};

int main()
{
	TreeNode *root = new TreeNode(1);
	//root->left = new TreeNode(2);
	//root->right = new TreeNode(3);
	//root->left->right = new TreeNode(4);
	//root->right->left = new TreeNode(5);

	Solution s;
	cout << s.sumNumbers(root) << endl;
	
}
