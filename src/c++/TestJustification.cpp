class Solution {
public:
	vector<string> fullJustify(vector<string>& words, int maxWidth) {
		vector<string> res;
		vector<string> line;
		int n = (int)words.size();
		int len = 0;
		for (int i = 0; i < n; i++) {
			len += words[i].size();
			if (len > maxWidth) {
				res.push_back(genLine(line, maxWidth, len - words[i].size() - 1));
				line.clear();
				len = words[i].size();
			}
			len++;
			line.push_back(words[i]);
		}
		string tmp(line[0]);
		for (int i = 1; i < line.size(); i++) {
			tmp = tmp + " " + line[i];
		}
		tmp = tmp + string(maxWidth - tmp.size(), ' ');
		res.push_back(tmp);
		return res;
	}
	string genLine(vector<string> &line, int maxWidth, int len) {
		int n = line.size();
		int l = maxWidth - len;
        if (n == 1) {
			return line[0] + string(l, ' ');
		}
		int a1 = (l / (n - 1)) + 1;
		int a2 = l % (n-1);
		string res(line[0]);
		for (int i = 1; i < n; i++) {
			string sp(a1, ' ');
			if (i <= a2) {
				sp += " ";
			}
			res = res + sp + line[i];
		}
		return res;
	}
};
