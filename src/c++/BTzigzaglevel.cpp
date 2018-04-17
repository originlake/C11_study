//two stack
class Solution {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		stack<TreeNode*> l;
		stack<TreeNode*> r;
		vector<vector<int>> res;
		l.push(root);
		int dep = 0;
		while (!l.empty() && !r.empty()) {
			TreeNode* cur;
			res.push_back(vector<int>());
			while (!l.empty()) {
				cur = l.top();
				l.pop();
				res[dep].push_back(cur->val);
				if (cur->left) r.push(cur->left);
				if (cur->right) r.push(cur->right);
			}
			dep++;
			res.push_back(vector<int>());
			while (!r.empty()) {
				cur = r.top();
				r.pop();
				res[dep].push_back(cur->val);
				if (cur->right) l.push(cur->right);
				if (cur->left) l.push(cur->left);
			}
			dep++;
		}
		
		return res;
	}
};
