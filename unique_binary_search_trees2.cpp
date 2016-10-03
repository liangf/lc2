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
	vector<TreeNode *> generateTrees(int n) {
		return insert(1, n);
	}
	vector<TreeNode *> insert(int start, int end) {
		vector<TreeNode *> result;
		if (start > end) {
			result.push_back(NULL);
			return result;
		}

		for (int i=start; i<=end; ++i) {
			vector<TreeNode *> left = insert(start, i-1);
			vector<TreeNode *> right = insert(i+1, end);
			for (int j=0; j<left.size(); ++j) {
				for (int k=0; k<right.size(); ++k) {
					TreeNode *root = new TreeNode(i);
					root->left = left[j];
					root->right = right[k];
					result.push_back(root);
				}
			}
		}
		return result;
	}
};

void print(TreeNode *root)
{
	if (root == NULL) return;

	cout << root->val << endl;
	print(root->left);
	print(root->right);
}

int main()
{
	Solution s;
	vector<TreeNode *> res = s.generateTrees(3);

	for (int i=0; i<res.size(); ++i) {
		print(res[i]);
		cout << endl;
	}
}
