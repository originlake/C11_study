// backtracking

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include  <sstream>

using namespace std;

class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		if (board.empty() || board[0].empty()) return 0;
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[0].size(); j++) {
				if (myExist(board, word, i, j, 0)) {
					return 1;
				}
			}
		}
		return 0;
	}

	bool myExist(vector<vector<char>>& board, string word, int i,int j,int s) {
		if (s == word.size()) return 1;
		if (i >= 0 && i < board.size() && j >= 0 && j < board[0].size() && board[i][j] == word[s]) {
			char tmp = board[i][j];
			board[i][j] = '\0';
			if (myExist(board, word, i + 1, j, s + 1) || myExist(board, word, i - 1, j, s + 1) || myExist(board, word, i, j + 1, s + 1) || myExist(board, word, i, j - 1, s + 1)) {
				return 1;
			}
			board[i][j] = tmp;
		}
		return 0;
	}
};
int main() {
	vector<vector<char>> a = { {'a','b'},{'c','d'} };
	cout << Solution().exist(a, "abcd") << endl;
}


