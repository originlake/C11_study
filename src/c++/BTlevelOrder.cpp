//Binary Tree Level Order Traversal
class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> res;
		myFun(res, root, 0);
		return res;
	}
	void myFun(vector<vector<int>> &res, TreeNode* cur, int depth) {
		if (!cur) return;
		if (res.size() < depth + 1) res.push_back(vector<int>());
		res[depth].push_back(cur->val);
		myFun(res, cur->left, depth + 1);
		myFun(res, cur->right, depth + 1);
	}
};
