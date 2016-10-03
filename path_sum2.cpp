#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
	int val;	
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<vector<int> > pathSum(TreeNode *root, int sum) {
		vector<int> result;
		vector<vector<int> > solution;
		dfs(root, sum, result, solution);
		return solution;
	}
	void dfs(TreeNode *root, int sum, vector<int> &result, vector<vector<int> > &solution) {
		if (root == NULL) return;
		if (root->left==NULL && root->right==NULL) {
			result.push_back(root->val);
			if (sum == root->val) solution.push_back(result);
			result.pop_back();
			return;	
		}
		result.push_back(root->val);
		dfs(root->left, sum-root->val, result, solution);
		dfs(root->right, sum-root->val, result, solution);
		result.pop_back();
	}
};

int main()
{
	TreeNode *root = new TreeNode(5);
	root->left = new TreeNode(4);
	root->right = new TreeNode(8);
	root->left->left = new TreeNode(11);
	root->right->left = new TreeNode(13);
	root->right->right = new TreeNode(4);
	root->left->left->left = new TreeNode(7);
	root->left->left->right = new TreeNode(2);
	root->right->right->left = new TreeNode(5);
	root->right->right->right = new TreeNode(1);

	Solution s;
	vector<vector<int> > sol = s.pathSum(root, 22);
	for (int i=0; i<sol.size(); ++i) {
		for (int j=0; j<sol[i].size(); ++j) {
			cout << sol[i][j] << " ";
		}
		cout << endl;
	}
}
