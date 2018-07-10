class Solution {
public:
	bool isNumber(string s) {
		int n = (int)s.size();
		int s0 = 0, e0 = n, s1 = 0, e1 = n;
		bool isExp = false;
		// skip <sp>
		for (int i = 0; i < n; i++) {
			if (s[i] != ' ') {
				s0 = i;
				break;
			}
		}
		// empty string
		if (s0 == n) {
			return false;
		}
		//skip sign
		if (s[s0] == '+' || s[s0] == '-') s0++;
		//find first end
		for (int i = s0; i < n; i++) {
			// has exp
			if (s[i] == 'e') {
				isExp = true;
				e0 = i;
				break;
			}
			// no exp
			if (s[i] == ' ') {
				e0 = i;
				break;
			}
			// not valid
			if (s[i] != '.' && (s[i]<'0' || s[i]>'9')) {
				return false;
			}
		}
		if (!isMyNumber(s, s0, e0)) return false;
		if (isExp) {
			s0 = e0 + 1;
			e0 = n;
			if (s[s0] == '+' || s[s0] == '-') s0++;
			for (int i = s0; i < n; i++) {
				// end
				if (s[i] == ' ') {
					e0 = i;
					break;
				}
				// not valid
				if (s[i]<'0' || s[i]>'9') {
					return false;
				}
			}
			if (!isMyNumber(s, s0, e0)) return false;
		}
		for (int i = e0; i < n; i++) {
			if (s[i] != ' ') return false;
		}
		return true;
	}

	bool isMyNumber(string s, int start, int end) {
		bool isDec = false;
        bool hasDig = false;
		if (start == end) return false;
		for (int i = start; i < end; i++) {
			if (s[i] == '.') {
				if (isDec) return false;
				isDec = true;
			}
            else{hasDig = true;}
		}
		return hasDig;
	}
};
