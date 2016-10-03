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
	vector<int> inorderTraversal(TreeNode *root) {
		vector<int> result;
		if (root == NULL) return result;

		unordered_map<TreeNode*, bool> umap;
		stack<TreeNode*> stk;
		stk.push(root);
		umap[root] = true;
		while ( !stk.empty() ) {
			TreeNode *cur = stk.top();
			if (cur->left && umap.find(cur->left) == umap.end()) {
				stk.push(cur->left);
				umap[cur->left] = true;
			}	
			else if (cur->right && umap.find(cur->right) == umap.end()) {
				stk.push(cur->right);
				umap[cur->right] = true;
				if (cur->left) result.push_back(cur->val);
			}
			else {
				if (cur->right==NULL) result.push_back(cur->val);
				stk.pop();
			}
		}	
		return result;
	}
};
*/

class Solution {
public:
	vector<int> inorderTraversal(TreeNode *root) {
		vector<int> result;
		stack<TreeNode*> stk;

		while (root || !stk.empty()) {
			while (root != NULL) {
				stk.push(root);
				root = root->left;
			} 
			result.push_back(stk.top()->val);
			root = stk.top()->right;
			stk.pop();
		}
		return result;
	}
};
int main()
{
	TreeNode *root = new TreeNode(4);
	root->left = new TreeNode(2);
	//root->right = new TreeNode(5);
	//root->left->left = new TreeNode(1);
	root->left->right = new TreeNode(3);

	Solution s;
	vector<int> result = s.inorderTraversal(root);
	for (int i=0; i<result.size(); i++) {
		cout << result[i] << endl;
	}
}
