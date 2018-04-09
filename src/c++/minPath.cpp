class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		if (grid.empty() || grid[0].empty()) return 0;
		int m = grid.size();
		int n = grid[0].size();
		vector<int> a(n, 0);
		a[0] = grid[0][0];
		for (int i = 0; i < m; i++) {
			if (i > 0) a[0] += grid[i][0];
			for (int j = 1; j < n; j++) {
				if (i == 0) {
					a[j] = a[j-1]+grid[i][j];
				}
				else {
					a[j] = grid[i][j] + (a[j] < a[j - 1] ? a[j] : a[j - 1]);
				}
			}
		}
		return a[n - 1];
	}
};
