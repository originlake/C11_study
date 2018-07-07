class Solution {
public:
	bool isMatch(string s, string p) {
		int len_s = (int)s.size();
		int len_p = (int)p.size();
		vector<vector<bool>> dp(len_s+1, vector<bool>(len_p+1,false));
		dp[0][0] = true;

		for (int j = 1; j < len_p + 1; ++j) {
			if (p[j-1] != '*') {
				break;
			}
			dp[0][j] = 1;
		}

		for (int i = 1; i < len_s+1; ++i) {
			for (int j = 1; j < len_p + 1; ++j) {
				if (s[i-1] == p[j-1] || p[j-1] == '?') {
					dp[i][j] = dp[i - 1][j - 1];
				}
				if (p[j-1] == '*') {
					dp[i][j] = dp[i - 1][j - 1] || dp[i - 1][j] || dp[i][j - 1];
				}
			}
		}

		return dp[len_s][len_p];
	}
};
