class Solution {
public:
	bool isMatch(string s1, string s2) {
		if (s1.size() != s2.size()) {
			return false;
		}
		unordered_map<char, int> map;
		for (char c : s1) {
			map[c]++;
		}
		for (char c : s2) {
			if (--map[c] < 0) {
				return false;
			}
		}
		return true;
	}

	bool isScramble(string s1, string s2) {
		int len = s1.size();
		if (s1 == s2) return true;
		if (!isMatch(s1, s2)) {
			return false;
		}
		for (int i = 1; i < len; i++) {
			if (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i))) {
				return true;
			}
			if (isScramble(s1.substr(0, i), s2.substr(len - i)) && isScramble(s1.substr(i), s2.substr(0, len - i))) {
				return true;
			}
		}
		return false;
	}
};
