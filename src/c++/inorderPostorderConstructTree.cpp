#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<unordered_set>
#include<unordered_map>
#include<stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
	/*TreeNode * buildTree(vector<int>& inorder, vector<int>& postorder) {
		if (inorder.size() == 0) {
			return NULL;
		}
		int len = inorder.size();
		TreeNode *res = new TreeNode(postorder[len - 1]);
		if (len == 1) {
			return res;
		}

		int i = 0;
		for (i = 0; i < len - 1; i++) {
			if (inorder[i] == res->val) {
				break;
			}
		}
		vector<int> inorder_l(inorder.begin(), inorder.begin() + i);
		vector<int> postorder_l(postorder.begin(), postorder.begin() + i);
		vector<int> inorder_r(inorder.begin() + i + 1, inorder.end());
		vector<int> postorder_r(postorder.begin() + i, postorder.end() - 1);
 		res->left = buildTree(inorder_l, postorder_l);
		res->right = buildTree(inorder_r, postorder_r);

		return res;
	}*/
	TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
		return myBuildTree(inorder, postorder, 0, inorder.size(), 0, postorder.size());
	}
	
	// Recursion
	// il, ir left right index of inorder
	// pl, pr left right index of postorder
	// Last element is always root of postorder tree
	// Based on the last element, find the root of inorder tree, and then can determine left tree and right tree
	TreeNode *myBuildTree(vector<int>& inorder, vector<int>& postorder, int il, int ir, int pl, int pr) {
		int len = pr - ir;
		if (len == 0) {
			return NULL;
		}
		TreeNode *res = new TreeNode(postorder[pr - 1]);
		if (len == 1) {
			return res;
		}
		int i = 0;
		for (i = 0; i < len; i++) {
			if (inorder[il + i] == res->val) {
				break;
			}
		}
		res->left = myBuildTree(inorder, postorder, il, il + i, pl, pl + i);
		res->right = myBuildTree(inorder, postorder, il + i + 1, ir, pl + i, pr - 1);
		return res;
	}
};

int main() {
	vector<int> res{ 1,2,3,4,5 };
	int a = vector<int>(res.begin(), res.begin()+1).size();
	cout << a << endl;
	return 0;
}
