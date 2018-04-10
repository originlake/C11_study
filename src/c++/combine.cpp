//backtracking
class Solution {
public:
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> res;
		vector<int> ans;
		myCombine(res, ans, n, k);
		return res;
	}

	void myCombine(vector<vector<int>> &res, vector<int> &ans, int n, int k) {
		if (k == 0) {
			res.push_back(ans);
			return;
		}
		for (int i = 1; i <= n; i++) {
			if (find(ans.begin(), ans.end(), i) == ans.end()) {
				ans.push_back(i);
				myCombine(res, ans, n, k-1);
				ans.pop_back();
			}
		}
	}
};
