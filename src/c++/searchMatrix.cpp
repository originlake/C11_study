//simple binary search
class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.empty() || matrix[0].empty()) return false;
		int m = matrix.size(), n = matrix[0].size();
		int l = 0, r = m * n - 1,mid;
		while (l <= r) {
			mid = (l + r) / 2;
			if (target < matrix[mid / n][mid % 4]) {
				r = mid - 1;
			}
			else if (target > matrix[mid / n][mid % 4]) {
				l = mid + 1;
			}
			else return 1;
		}
		return 0;
	}
};
