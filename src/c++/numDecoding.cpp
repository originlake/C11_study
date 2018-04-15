//bottom-up dp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include  <sstream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}	
};
class Solution {
public:
	int numDecodings(string s) {
		if (s.empty() || (s.size()==1 && s[0]=='0')) return 0;
		int n = (int)s.size();
		vector<int> res(n+1, 0);
		res[n] = 1;
		int i;
		if (s[n - 1] != '0') {
			res[n - 1] = 1;
			i = n - 2;
		}
		else {
			res[n - 2] = (s[n - 2] > '0' && s[n - 2] < '3') ? 1 : 0;
			i = n - 3;
		}
		for (; i >= 0; i--) {
			if (s[i] == '0') {
				res[i] = 0;
			}
			else if (s[i] == '1') {
				res[i] = res[i + 1] + res[i + 2];
			}
			else if (s[i] == '2') {
				res[i] = s[i + 1] > '6' ? res[i + 1] : (res[i + 1] + res[i + 2]);
			}
			else {
				res[i] = res[i + 1];
			}
		}
		return res[0];
	}

};
int main() {
	cout << Solution().numDecodings("0");
}
