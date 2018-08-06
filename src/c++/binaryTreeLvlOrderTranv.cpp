class Solution {
public:
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> res;
		vector<int> tmp;
		vector<TreeNode*> v1;
		vector<TreeNode*> v2;
        if(root == NULL) return res;
		v1.push_back(root);
		while (!v1.empty() || !v2.empty()) {
			if (!v1.empty()) {
				tmp.clear();
				for (auto node : v1) {
					tmp.push_back(node->val);
					if (node->left != NULL) {
						v2.push_back(node->left);
					}
					if (node->right != NULL) {
						v2.push_back(node->right);
					}
				}
				v1.clear();
			}
			else if (!v2.empty()) {
				tmp.clear();
				for (auto node : v2) {
					tmp.push_back(node->val);
					if (node->left != NULL) {
						v1.push_back(node->left);
					}
					if (node->right != NULL) {
						v1.push_back(node->right);
					}
				}
				v2.clear();
			}
			res.insert(res.begin(), tmp);
		}
		return res;
	}
};
