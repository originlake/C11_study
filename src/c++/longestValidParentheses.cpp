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
	int longestValidParentheses(string s) {
		int len = s.size();
		stack<int> myStack;
		vector<int> markArray(len, 0);
		for (int i = 0; i < len; i++) {
			if (s[i] == '(') {
				myStack.push(i);
			}
			else if (!myStack.empty()) {
				markArray[i] = 1;
				markArray[myStack.top()] = 1;
				myStack.pop();
			}
		}

		int cnt = 0;
		int maxCnt = 0;
		for (int i = 0; i < len; i++) {
			if (markArray[i] == 1) {
				cnt++;
			}
			else {
				if (cnt > maxCnt) {
					maxCnt = cnt;
				}
				cnt = 0;
			}
		}
		if (cnt > maxCnt) {
			maxCnt = cnt;
		}
		return maxCnt;
	}
};
