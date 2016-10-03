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
	TreeNode *sortedArrayToBST(vector<int> &num) {
		return insert(num, 0, num.size()-1);
	}
	TreeNode* insert(vector<int> &num, int left, int right) {
		if (left > right) return NULL;		

		int mid = left + (right-left)/2;
		TreeNode *root = new TreeNode(num[mid]);
		root->left = insert(num, left, mid-1);
		root->right = insert(num, mid+1, right);
	}
};


int main()
{

}
