class Solution {
public:
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>> res;
		if (root == NULL) return res;
		vector<int> tmp;
		myPathSum(root, res, tmp, sum, 0);
		return res;
	}
	void myPathSum(TreeNode* root,vector<vector<int>> &res, vector<int> &tmp,int sum, int cursum) {
		if (root->left == NULL && root->right == NULL) {
			if (sum == (cursum + root->val)) {
				tmp.push_back(root->val);
				res.push_back(tmp);
				tmp.pop_back();
			}
			return;
		}
		tmp.push_back(root->val);
		if (root->left != NULL) {
			myPathSum(root->left, res, tmp, sum, cursum+ root->val);
		}
		if (root->right != NULL) {
			myPathSum(root->right, res, tmp, sum, cursum + root->val);
		}
		tmp.pop_back();
		return;
	}
};
