#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <unordered_map>
//be sure to check overflow when trans negative to positive
using namespace std;
class Solution {
public:
	//spiral order 1
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		if (matrix.empty()) return vector<int>();
		vector<int> ans;
		int ml = 0, nl = 0;
		int mr = matrix.size()-1;
		int nr = matrix[0].size()-1;
		int i=0, di=0, j=0, dj=1;
		while (ml<=mr&&nl<=nr) {
			ans.push_back(matrix[i][j]);
			if (dj == 1 && j == nr) {
				ml++;
				dj = 0;
				di = 1;
			}
			if (di == 1 && i == mr) {
				nr--;
				dj = -1;
				di = 0;
			}
			if (dj == -1 && j == nl) {
				mr--;
				dj = 0;
				di = -1;
			}
			if (di == -1 && i == ml) {
				nl++;
				dj = 1;
				di = 0;
			}
			i += di;
			j += dj;
		}
		return ans;
	}

	//spiral order 2
	vector<vector<int>> generateMatrix(int n) {
		if (n == 0) return vector<vector<int>>();
		vector<vector<int>> ans(n,vector<int>(n,0));
		int ml = 0, nl = 0, mr = n - 1, nr = n - 1;
		int i = 0, di = 0, j = 0, dj = 1;
		int num = 1;
		while (ml <= mr && nl <= nr) {
			ans[i][j] = num;
			num++;
			if (dj == 1 && j == nr) {
				ml++;
				dj = 0;
				di = 1;
			}
			if (di == 1 && i == mr) {
				nr--;
				dj = -1;
				di = 0;
			}
			if (dj == -1 && j == nl) {
				mr--;
				dj = 0;
				di = -1;
			}
			if (di == -1 && i == ml) {
				nl++;
				dj = 1;
				di = 0;
			}
			i += di;
			j += dj;
		}
		return ans;
	}
};
int main() {
	vector<vector<int>> a = Solution().generateMatrix(2);
	for (vector<int> vi : a) {
		for (int vj : vi) {
			cout << vj << " ";
		}
		cout << endl;
	}
}
