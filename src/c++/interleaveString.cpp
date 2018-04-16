class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		vector<vector<bool>>  res(s1.size() + 1, vector<bool>(s2.size(), 0));
		s1 = '0' + s1;
		s2 = '0' + s2;
		s3 = '0' + s3;
		for (int i = 0; i < s1.size(); i++) {
			for (int j = 0; j < s2.size(); j++) {
				if (i + j == 0) res[i][j] = 1;
				else {
					res[i][j] = (i > 0 && res[i - 1][j] && s3[i + j] == s1[i]) || (j > 0 && res[i][j - 1] && s3[i + j] == s2[j]);
				}
			}
		}
		return res[s1.size() - 1][s2.size() - 1];
	}
};
