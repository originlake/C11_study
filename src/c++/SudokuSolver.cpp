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
	void solveSudoku(vector<vector<char>>& board) {
		unordered_map<string, bool> check;
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
					check[s[0]] = true; check[s[1]] = true; check[s[2]] = true;
					s[0].clear(); s[1].clear(); s[2].clear();
				}
			}
		}
		mySolver(board, check);
		return;
	}

	bool mySolver(vector<vector<char>>& board, unordered_map<string, bool>& check) {
		int i = 0, j = 0;
		string s[3];
		for (i = 0; i < 9; i++) {
			for (j = 0; j < 9; j++) {
				if (board[i][j] == '.') {
					break;
				}
			}
			if (j != 9) {
				break;
			}
		}
		if (i == 9 && j == 9) {
			return true;
		}
		for (int k = 1; k <= 9; k++) {
			board[i][j] = '0' + k;
			//row
			s[0].push_back(board[i][j]); s[0].push_back('+'); s[0].push_back('0' + i);
			//column
			s[1].push_back(board[i][j]); s[1].push_back('-'); s[1].push_back('0' + j);
			//3 by 3 block
			s[2].push_back(board[i][j]); s[2].push_back('*'); s[2].push_back('0' + (i / 3 * 3 + j / 3));
			if (check[s[0]] || check[s[1]] || check[s[2]]) {
				s[0].clear(); s[1].clear(); s[2].clear();
				continue;
			}
			check[s[0]] = true; check[s[1]] = true; check[s[2]] = true;
			if (mySolver(board, check)) {
				return true;
			}
			check[s[0]] = false; check[s[1]] = false; check[s[2]] = false;
			s[0].clear(); s[1].clear(); s[2].clear();
		}
		board[i][j] = '.';
		return false;
	}
};
int main() {
	vector<vector<char>> board{ { '5', '3', '.', '.', '7', '.', '.', '.', '.' },{ '2', '.', '.', '.', '.', '.', '.', '.', '.' },{ '3', '.', '.', '.', '.', '.', '.', '.', '.' },{ '4', '.', '.', '.', '.', '.', '.', '.', '.' },{ '5', '.', '.', '.', '.', '.', '.', '.', '.' },{ '6', '.', '.', '.', '.', '.', '.', '.', '.' },{ '7', '.', '.', '.', '.', '.', '.', '.', '.' },{ '8', '.', '.', '.', '.', '.', '.', '.', '.' },{ '9', '.', '.', '.', '.', '.', '.', '.', '.' } };
	Solution().solveSudoku(board);
	return 0;
}
