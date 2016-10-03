#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
		int level = 0;
		vector<vector<int> > solution;
		if (root == NULL) return solution;
		queue<TreeNode*> cur;
		cur.push(root);
	
		while ( !cur.empty() ) {
			++level;
			queue<TreeNode*> next;
			vector<int> result;
			while ( !cur.empty() ) {
				TreeNode *n = cur.front();
				cur.pop();
				result.push_back(n->val);
				if (n->left) next.push(n->left);
				if (n->right) next.push(n->right);
			}
			if (level%2 == 0) reverse(result.begin(), result.end());	
			solution.push_back(result);
			cur = next;
		}
		return solution;
	}
};

int main()
{
	TreeNode *root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);

	Solution s;
	vector<vector<int> > sol = s.zigzagLevelOrder(root);
	for (int i=0; i<sol.size(); ++i) {
		for (int j=0; j<sol[i].size(); ++j) {
			cout << sol[i][j] << " ";
		}
		cout << endl;
	}
}
