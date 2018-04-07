#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int tmp;
		int n = matrix.size();
		int j = 0;
		for (int i = 0; i < n/2; i++) {
			for (int j = i; j < n - 1 - i; j++) {
				tmp = matrix[i][j];
				matrix[i][j] = matrix[n - 1 - j][i];
				matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
				matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
				matrix[j][n - 1 - i] = tmp;
			}
		}
	}
};
int main() {
	vector<vector<int>> a = { };
	Solution().rotate(a);
	return 0;
}
