#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<unordered_set>
#include<unordered_map>
#include<stack>
using namespace std;

class Solution {
public:
	vector<vector<string>> solveNQueens(int n) {
		vector<vector<string>> res;
		vector<string> tmp(n, string(n, '.'));
		vector<bool> col(n, false);
		vector<bool> r_diag(2 * n - 1, false);// x + y   '/' shape
		vector<bool> l_diag(2 * n - 1, false);// y - x + n - 1  '\' shape
		solver(res, tmp, col, r_diag, l_diag, 0, n);
		return res;
	}

	void solver(vector<vector<string>> &res, vector<string> &tmp, vector<bool> &col, vector<bool> &r_diag, vector<bool> &l_diag, int k, int n) {
		if (k == n) {
			res.push_back(tmp);
			return;
		}
		for (int i = 0; i < n; i++) {
			if (col[i] || r_diag[i + k] || l_diag[i - k + n - 1]) {
				continue;
			}
			tmp[k][i] = 'Q';
			col[i] = true; r_diag[i + k] = true; l_diag[i - k + n - 1] = true;
			solver(res, tmp, col, r_diag, l_diag, k + 1, n);
			tmp[k][i] = '.';
			col[i] = false; r_diag[i + k] = false; l_diag[i - k + n - 1] = false;
		}
		return;
	}
};
