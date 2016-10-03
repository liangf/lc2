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
	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
		return insert(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
	}
	TreeNode *insert(vector<int> &preorder, int prestart, int preend,
					vector<int> &inorder, int instart, int inend) {
		if (prestart > preend) return NULL;
		
		TreeNode *root = new TreeNode(preorder[prestart]);	
		int mid = getIndex(inorder, preorder[prestart]);
		root->left = insert(preorder, prestart+1, prestart+mid-instart, inorder, instart, mid-1);
		root->right = insert(preorder, prestart+mid-instart+1, preend, inorder, mid+1, inend);
		return root;
	}
	int getIndex(vector<int> &vec, int val) {
		for (int i=0; i<vec.size(); ++i) {
			if (vec[i] == val) return i;
		}
		return -1;
	}
};

void inOrder(TreeNode *root) 
{
	if (root == NULL) return;
		
	inOrder(root->left);
	cout << root->val << endl;
	inOrder(root->right);
}

int main()
{
	vector<int> inorder;
	inorder.push_back(1);
	inorder.push_back(2);
	inorder.push_back(3);
	inorder.push_back(4);
	inorder.push_back(5);

	vector<int> preorder;
	preorder.push_back(4);
	preorder.push_back(2);
	preorder.push_back(1);
	preorder.push_back(3);
	preorder.push_back(5);

	Solution s;
	TreeNode *root = s.buildTree(preorder, inorder);
	inOrder(root);	
}
