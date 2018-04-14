class Solution {
public:
	vector<int> grayCode(int n) {
		vector<int> res{ 0 };
		for (int i = 0; i < n; i++) {
			int m = (int)res.size();
			for (int j = m-1; j >= 0; j--) {
				res.push_back((1 << i) + res[j]);
			}
		}
		return res;
	}
};
