class Solution {
public:
  //DP
	int numTrees(int n) {
		vector<int> res(n+1, 0);
		res[0] = 1;
		for (int i = 1; i <= n; i++) {
			int num = 0;
			int j;
			for (j = 0; j < i/2; j++) {
				num += res[j - 0] * res[i - 1 - j];
			}
			num *= 2;
			if (i % 2 != 0) num += res[j] * res[j];
			res[i] = num;
		}
		return res[n];
	}
  //Recursive (can use DP but need to clone all the nodes, so maybe the complexity is same as recursive version)
	vector<TreeNode*> generateTrees(int n) {
		return myGenerateTrees(1,n);
	}
	vector<TreeNode*> myGenerateTrees(int l, int r) {
		vector<TreeNode*> res;
		if (l > r) {
			res.push_back(NULL);
			return res;
		}

		if (l == r) {
			res.push_back(new TreeNode(l));
			return res;
		}

		for (int i = l; i <= r; i++) {
			vector<TreeNode*> left = myGenerateTrees(l, i - 1);
			vector<TreeNode*> right = myGenerateTrees(i+1, r);
			for (auto nl : left) {
				for (auto nr : right) {
					TreeNode* root = new TreeNode(i);
					root->left = nl;
					root->right = nr;
					res.push_back(root);
				}
			}
		}
		return res;
	}
};
