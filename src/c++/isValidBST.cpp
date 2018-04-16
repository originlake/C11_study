class Solution {
public:
	bool isValidBST(TreeNode* root) {
		bool isFirst = true;
		int cmp;
		stack<TreeNode*> res;
		TreeNode* ptr = root;
		while (!res.empty() || ptr != NULL) {
			if (ptr != NULL) {
				res.push(ptr);
				ptr = ptr->left;
			}
			else {
				TreeNode* cur = res.top();
				res.pop();
				if (isFirst) {
					isFirst = false;
					cmp = cur->val;
				}
				else if (cur->val <= cmp) {
					return false;
				}
				else {
					cmp = cur->val;
				}
				ptr = cur->right;
			}
		}
		return true;
	}
};
