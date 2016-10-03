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
	TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
		return insert(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
	}
	TreeNode *insert(vector<int> &inorder, int instart, int inend, 
					vector<int> &postorder, int postart, int poend) {
		if (instart > inend) return NULL;	
	
		TreeNode *root = new TreeNode(postorder[poend]);
		int mid = getIndex(inorder, postorder[poend]); 
		root->left = insert(inorder, instart, mid-1, postorder, postart, postart+mid-instart-1);
		root->right = insert(inorder, mid+1, inend, postorder, postart+mid-instart, poend-1);
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
	//inorder.push_back(5);

	vector<int> postorder;
	postorder.push_back(1);
	postorder.push_back(3);
	postorder.push_back(4);
	postorder.push_back(2);
	//postorder.push_back(5);

	Solution s;
	TreeNode *root = s.buildTree(inorder, postorder);
	inOrder(root);	
}
