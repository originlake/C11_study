#include<iostream>
#include<vector>
#include<string>
#include <algorithm>
using namespace std;

//Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		int n = preorder.size();
		if (n <= 0) return NULL;
		return myBuildTree(preorder, inorder, 0, n, 0, n);
	}
	TreeNode* myBuildTree(vector<int>& preorder, vector<int>& inorder, int pl, int pr, int il, int ir) {
		if (il >= ir || pl == pr) return NULL;
		TreeNode* root = new TreeNode(preorder[pl]);
		int i = il;
		while (inorder[i] != preorder[pl]) i++;
		int n = i - il;
		root->left = myBuildTree(preorder, inorder, pl + 1, pl + n + 1, il, il + n);
		root->right = myBuildTree(preorder, inorder, pl + n +1 , pr, il + n + 1, ir);
		return root;
	}
};
int main() {
	vector<int> preorder{ 3,9,20,15,7 };
	vector<int> inorder{ 9,3,15,20,7 };
	TreeNode* root = Solution().buildTree(preorder, inorder);
	return 0;
}
