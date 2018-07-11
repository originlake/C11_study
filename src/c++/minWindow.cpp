class Solution {
public:
	string minWindow(string s, string t) {
		int l = 0, r = 0;
		int maxlen = INT_MAX, start = 0;
		unordered_map<char, int> map;
		for (char c : t) {
			map[c] += 1;
		}
		int cnt = t.size();
		while(r<s.size()) {
			if (map[s[r++]]-- > 0) {
				cnt--;
			}
			while (cnt == 0) {
				if (r - l < maxlen) {
					start = l;
					maxlen = r - l;
				}
				if (map[s[l++]]++ == 0) {
					cnt++;
				}
			}
		}
		return (maxlen == INT_MAX ? "" : s.substr(start, maxlen));
	}
};
