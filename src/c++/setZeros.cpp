//using the first row contains 0 to mark the columns that have 0
class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		if (matrix.empty() || matrix[0].empty()) return;
		int m = matrix.size();
		int n = matrix[0].size();
		int r1=m;
		bool is0 = false;
		for (int i = 0; i < m ; i++) {
			for (int j = 0; j < n ; j++) {
				if ( r1 == m && matrix[i][j] == 0) {
					r1 = i;
					break;
				}
				if (r1 != m && matrix[i][j] == 0) {
					matrix[r1][j] = 0;
					is0 = true;
				}
			}
			if (is0) {
				for (int j = 0; j < n; j++) {
					matrix[i][j] = 0;
				}
				is0 = false;
			}

		}

		if (r1 == m) return;
		
		for (int j = n - 1; j >= 0 ; j--) {
			if (matrix[r1][j] == 0) {
				for (int i = 0; i < m; i++) {
					matrix[i][j] = 0;
				}
			}
		}
        for (int j = 0; j < n; j++) {
			matrix[r1][j] = 0;
		}
	}
};
