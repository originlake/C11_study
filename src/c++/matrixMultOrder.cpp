#include <iostream>
#include <string>
#include <conio.h>
#include <vector>
#include <map>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	//Bottom-up DP, solving matrix mutiply problem
	pair<vector<vector<int>>, vector<vector<int>>> matrixMultOrder(vector<int> &p){
		int n = p.size()-1;
		int i, j, k, l, tmp;
		vector<vector<int>> m(n, vector<int>(n));
		vector<vector<int>> s(n, vector<int>(n));
		for (l = 2; l <=n; l++) {
			for (i = 0; i < n-l+1; i++) {
				j = i + l - 1;
				m[i][j] = INT_MAX;
				for (k = i; k < j; k++) {
					tmp = m[i][k] + m[k + 1][j] + p[i] * p[k + 1] * p[j + 1];
					if (tmp < m[i][j]) {
						m[i][j] = tmp;
						s[i][j] = k;
					}
				}
			}
		}
		cout << strMatrixOrder(s, 0, n - 1);
		return pair<vector<vector<int>>, vector<vector<int>>>(m,s);
	}

	string strMatrixOrder(vector<vector<int>> s, int i, int j) {
		char *a;
		if (i == j) {
			return "A" + to_string(i);
		}
		else {
			return "(" + strMatrixOrder(s, i, s[i][j]) + strMatrixOrder(s, s[i][j] + 1, j) + ")";
		}
	}

};
int main() {
	vector<int> p = { 30,35,15,5,10,20,25 };
	pair<vector<vector<int>>, vector<vector<int>>> a = Solution().matrixMultOrder(p);
	return 0;
}
