class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		int n = (int)triangle.size();
		for (int i = n - 1; i >= 1; i--) {
			for (int j = 0; j < n - 1; j++) {
				int tmp = min(triangle[i][j], triangle[i][j + 1]);
				triangle[i - 1][j] += tmp;
			}
			n--;
		}
		return triangle[0][0];
	}
};
