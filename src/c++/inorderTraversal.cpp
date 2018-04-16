class Solution {
public:
	//recursive version
	/*vector<int> inorderTraversal(TreeNode* root) {
		vector<int> res;
		myTraversal(root, res);
		return res;
	}
	void myTraversal(TreeNode* cur, vector<int> &res) {
		if (!cur) return;
		myTraversal(cur->left, res);
		res.push_back(cur->val);
		myTraversal(cur->right, res);
		return;
	}*/
	//stack version, use addtional pointer
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> res;
		if (!root) return res;
		stack<TreeNode*> s;
		TreeNode *ptr=root;
		while (!s.empty() || ptr) {
			if (ptr) {
				s.push(ptr);
				ptr = ptr->left;
			}
			else {
				auto node = s.top();
				s.pop();
				res.push_back(node->val);
				ptr = node->right;
			}
		}
	}
};
