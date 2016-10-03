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
	int maxPathSum(TreeNode *root) {
		int maxSum = INT_MIN, maxLR;	
		maxLR = maxOnePath(root, maxSum);
		return maxSum;
	}
	int maxOnePath(TreeNode *root, int &maxSum) {
		if (root == NULL) return 0;
		
		int left = maxOnePath(root->left, maxSum);
		int right = maxOnePath(root->right, maxSum);
		int maxLR = max(max(left+root->val, right+root->val), root->val);
		maxSum = max(maxSum, max(maxLR, left+right+root->val));
		//cout << root->val << ",";
		//cout << "L:" << left << ",";
		//cout << "R:" << right << ",";
		//cout << "maxLR:" << maxLR << ",";
		//cout << "maxSum:" << maxSum << endl;
		return maxLR;
	}
};

int main()
{
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(-2);
	root->right = new TreeNode(3);

	Solution s;
	cout << s.maxPathSum(root) << endl;
}
