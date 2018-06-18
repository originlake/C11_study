#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<unordered_set>
using namespace std;

class Solution {
public:
	bool isMatch(string s, string p) {
		return myDPMatch(s, p);
	}
	//not DP
	bool myMatch(string s, string p, int i, int j) {
		bool res = false;
		//finish both
		if (j >= (int)p.size() && i >= (int)s.size()) {
			return true;
		}

		//finish p
		if (j >= (int)p.size() && i < (int)s.size()) {
			return false;
		}

		//skip 
		if (p[j] == '*') {
			return myMatch(s, p, i, j - 1);
		}

		//always skip *
		if (j < (int)p.size() - 1 && p[j + 1] == '*') {
			res = myMatch(s, p, i, j + 2);
		}
		//finish s
		if (i >= (int)s.size()) {
			return false || res;
		}

		if (s[i] == p[j] || p[j] == '.') {
			return myMatch(s, p, i + 1, j + 1) || res;
		}

		if (s[i] != p[j]) {
			return false || res;
		}
	}
	//DP (idea of LCS)
	//1. initialize dp matrix
	//2. if s[i]==p[j] or p[j]=='.' :  dp[i][j]=dp[i-1][j-1]
	//3. else if p[j]=='*' :
	//4.    if  s[i]==p[j-1] :  dp[i][j]=dp[i][j-2] or dp[i][j-1] or dp[i-1][j]
	//4.    else : dp[i][j]=dp[i][j-2]
	bool myDPMatch(string s, string p) {
		vector<vector<bool>> dp(s.size()+1, vector<bool>(p.size()+1, false));
		dp[0][0] = true;
		for (int j = 0; j < p.size(); j++) {
			if (p[j] == '*') dp[0][j + 1] = dp[0][j - 1];
		}
		for (int i = 0; i < s.size(); i++) {
			for (int j = 0; j < p.size(); j++) {
				if (s[i] == p[j] || p[j] == '.')	dp[i + 1][j + 1] = dp[i][j];
				if (p[j] == '*') {
					if (p[j - 1] != s[i] && p[j - 1] != '.') {
						dp[i + 1][j + 1] = dp[i + 1][j - 1];
					}
					else{
						dp[i + 1][j + 1] = dp[i + 1][j - 1] || dp[i + 1][j] || dp[i][j + 1];
					}
				}
			}
		}
		return dp[s.size()][p.size()];
	}
};
int main() {
	string a = "";
	string b = "*";
	cout << Solution().isMatch(a, b)<<endl;
	return 0;
}
