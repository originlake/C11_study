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
	//Bottom-up dp solving matrix mutiply problem
	int LCSLen(string x, string y) {
		int lx = x.size()+1;
		int ly = y.size()+1;
		vector<vector<int>> c(lx, vector<int>(ly));
		vector<vector<int>> b(lx, vector<int>(ly));
		for (int i = 1; i < lx; i++) {
			for (int j = 1; j < ly; j++) {
				if (x[i - 1] == y[j - 1]) {
					c[i][j] = c[i - 1][j - 1] + 1;
					b[i][j] = 0;//↖
				}
				else if (c[i][j - 1] > c[i - 1][j]) {
					c[i][j] = c[i][j - 1];
					b[i][j] = 1;//←
				}
				else {
					c[i][j] = c[i - 1][j];
					b[i][j] = 2;//↑
				}
			}
		}
		cout << LCSStr(b, x, lx - 1, ly - 1)<<endl;
		return c[lx - 1][ly - 1];
	}

	string LCSStr(vector<vector<int>> b, string x,int i,int j) {
		if (i < 1 || j < 1) {
			return "";
		}
		if (b[i][j] == 0) {
			return LCSStr(b,x,i-1,j-1)+x[i];
		}
		else if (b[i][j] == 1) {
			return LCSStr(b, x, i, j - 1);
		}
		else {
			return LCSStr(b, x, i-1, j);
		}

	}
};
int main() {
	string x = "ABCBDAB";
	string y = "BDCABA";
	cout << Solution().LCSLen(x, y) << endl;
}
