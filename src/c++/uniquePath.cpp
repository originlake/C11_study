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
};
