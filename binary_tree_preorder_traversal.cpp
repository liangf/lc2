#include <iostream>
#include <unordered_map>
#include <stack>
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/*
class Solution {
public:
	vector<int> preorderTraversal(TreeNode *root) {
		vector<int> result;
		if (root == NULL) return result;

		unordered_map<TreeNode*, bool> umap;
		stack<TreeNode*> stk;
		stk.push(root);
		umap[root] = true;
		result.push_back(root->val); 
		while ( !stk.empty() ) {
			TreeNode *cur = stk.top();
			if (cur->left && umap.find(cur->left)==umap.end()) {
				stk.push(cur->left);
				umap[cur->left] = true;
				result.push_back(cur->left->val);
			}	
			else if (cur->right && umap.find(cur->right)==umap.end()) {
				stk.push(cur->right);
				umap[cur->right] = true;
				result.push_back(cur->right->val);
			}
			else {
				stk.pop();
			}
		}	
		return result;
	}
};
*/
class Solution {
public:
	vector<int> preorderTraversal(TreeNode *root) {
		vector<int> result;
		stack<TreeNode *> stk;

		while (root || !stk.empty()) {
			while (root != NULL) {
				result.push_back(root->val);
				stk.push(root);
				root = root->left;
			}
			if (stk.top()->right) root = stk.top()->right;
			stk.pop();
		}
		return result;
	}
};

int main()
{
	TreeNode *root = new TreeNode(4);
	root->left = new TreeNode(2);
	root->right = new TreeNode(5);
	root->left->left = new TreeNode(1);
	root->left->right = new TreeNode(3);

	Solution s;
	vector<int> result = s.preorderTraversal(root);
	for (int i=0; i<result.size(); i++) {
		cout << result[i] << endl;
	}
}
