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
	bool isValidSudoku(vector<vector<char>>& board) {
		map<string, bool> check;
		string s[3];
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (board[i][j] != '.') {
					//row
					s[0].push_back(board[i][j]); s[0].push_back('+'); s[0].push_back('0' + i);
					//column
					s[1].push_back(board[i][j]); s[1].push_back('-'); s[1].push_back('0' + j);
					//3 by 3 block
					s[2].push_back(board[i][j]); s[2].push_back('*'); s[2].push_back('0' + (i / 3 * 3 + j / 3));
					if (check[s[0]] || check[s[1]] || check[s[2]]) {
						return false;
					}
					check[s[0]] = true; check[s[1]] = true; check[s[2]] = true;
					s[0].clear(); s[1].clear(); s[2].clear();
				}
			}
		}
		return true;
	}
};
int main() {
	vector<vector<char>> board = { {'.', '8', '7', '6', '5', '4', '3', '2', '1'},{'2', '.', '.', '.', '.', '.', '.', '.', '.'},{'3', '.', '.', '.', '.', '.', '.', '.', '.'},{'4', '.', '.', '.', '.', '.', '.', '.', '.'},{'5', '.', '.', '.', '.', '.', '.', '.', '.'},{'6', '.', '.', '.', '.', '.', '.', '.', '.'},{'7', '.', '.', '.', '.', '.', '.', '.', '.'},{'8', '.', '.', '.', '.', '.', '.', '.', '.'},{'9', '.', '.', '.', '.', '.', '.', '.', '.'} };

	cout << Solution().isValidSudoku(board);
}
