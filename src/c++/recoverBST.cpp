//morris
class Solution {
public:
	void recoverTree(TreeNode* root) {
		bool first = 1;
		int cmp;
		vector<TreeNode*> res;
		TreeNode* ptr=root;
		TreeNode* pre = NULL;
		while (ptr != NULL) {
			if (ptr->left == NULL) {
				if (pre!=NULL && pre->val > ptr->val) {
					res.push_back(pre);
					res.push_back(ptr);
				}
				pre = ptr;
				ptr = ptr->right;
			}
			else {
				TreeNode* rm = ptr->left;
				while (rm->right != NULL && rm->right != ptr) {
					rm = rm->right;
				}
				if (rm->right == ptr) {
					if (ptr != NULL && pre->val > ptr->val) {
						res.push_back(pre);
						res.push_back(ptr);
					}
					pre = ptr;
					ptr = ptr->right;
					rm->right = NULL;
				}
				else {
					rm->right = ptr;
					ptr = ptr->left;
				}
			}
		}
		TreeNode *p1, *p2;
		int tmp;
		if (res.size() == 2) {
			p1 = res[0];
			p2 = res[1];
		}
		else {
			p1 = res[0];
			p2 = res[3];
		}
		tmp = p1->val;
		p1->val = p2->val;
		p2->val = tmp;
		root;
		return;
	}
};
