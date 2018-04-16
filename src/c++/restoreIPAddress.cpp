//backtracking
class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		vector<string> res;
		vector<string> tmp;
		myRestore(res, s, tmp);
		return res;
	}
	void myRestore(vector<string> &res, string s, vector<string> &tmp) {
    //base case
		if (tmp.size() == 4) {
      //valid address
			if(s.size()==0) res.push_back(tmp[0] + "." + tmp[1] + "." + tmp[2] + "." + tmp[3]);
			return;
		}   
		if (s.size() >= 1) {
			tmp.push_back(s.substr(0, 1));
			myRestore(res, s.substr(1), tmp);
			tmp.pop_back();
      //'0' is the only case starts with 0
			if (s[0] == '0') return;
		}
		if (s.size() >= 2) {
			tmp.push_back(s.substr(0, 2));
			myRestore(res, s.substr(2), tmp);
			tmp.pop_back();
		}
		if (s.size() >= 3 && stoi(s.substr(0, 3)) < 256) {
			tmp.push_back(s.substr(0, 3));
			myRestore(res, s.substr(3), tmp);
			tmp.pop_back();
		}
	}
};
