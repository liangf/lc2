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
		while ( !stk.empty() ) {
			TreeNode *cur = stk.top();
			if (cur->left && umap.find(cur->left)==umap.end()) {
				stk.push(cur->left);
				umap[cur->left] = true;
			}	
			else if (cur->right && umap.find(cur->right)==umap.end()) {
				stk.push(cur->right);
				umap[cur->right] = true;
			}
			else {
				result.push_back(cur->val);
				stk.pop();
			}
		}	
		return result;
	}
};
*/
/*
class Solution {
public:
	vector<int> preorderTraversal(TreeNode *root) {
		vector<int> result;
		if (root == NULL) return result;

		TreeNode *newroot = new TreeNode(-1);
		newroot->left = root;
		stack<TreeNode*> stk;
		stk.push(root);
		TreeNode *cur, *pre;
		pre = newroot;
		while ( !stk.empty() ) {
			cur = stk.top();
			if (cur->left && (pre->left==cur||pre->right==cur)) {
				stk.push(cur->left);
			}
			else if (cur->right && (pre->left==cur||pre->right==cur||cur->left==pre)) {
				stk.push(cur->right);
			}	
			else {
				result.push_back(cur->val);
				stk.pop();
			}
			pre = cur;	
		}
		return result;
	}
};
*/

class Solution {
public:
	vector<int> preorderTraversal(TreeNode *root) {
		vector<int> result;
		stack<TreeNode*> stk;
		TreeNode *pre = NULL;

		while (root || !stk.empty()) {
			while (root != NULL) {
				stk.push(root);
				root = root->left;				
			}
			if (stk.top()->right && stk.top()->right!=pre) {
				root = stk.top()->right;
			}
			else {
				result.push_back(stk.top()->val);
				pre = stk.top();
				stk.pop();
			}
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
