#include <iostream>
#include <string>
#include <vector>

using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	int uniquePaths(int m, int n) {

		//spcae O(m*n)
		/*vector<vector<int>> a(m, vector<int>(n, 1));
		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				a[i][j] = a[i - 1][j] + a[i][j - 1];
			}
		}
		return a[m - 1][n - 1];*/
		//space O(n)
		vector<int> a(n, 1);
		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				a[j] = a[j] + a[j - 1];
			}
		}
		return a[n-1];
	}
	int uniquePathsWithObstacles(vector<vector<int>>& grid) {
		if (grid.empty() || grid[0].empty()) return 0;
		if (grid[0][0] == 1) return 0;
		int m= grid.size(),n = grid[0].size();
		vector<int> a(n,0);
		a[0] = 1;
		for (int i = 0; i < m; i++) {
			a[0] = (a[0] == 0 || grid[i][0] == 1) ? 0 : 1;
			for (int j = 1; j < n; j++) {
				a[j] = grid[i][j] == 1 ? 0 : (a[j] + a[j - 1]);
			}
		}
		return a[n - 1];
	}
};
