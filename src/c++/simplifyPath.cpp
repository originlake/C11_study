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
	string simplifyPath(string path) {
		path.push_back('/');
		vector<string> res;
		int i = 0;
		string str = "";
		while (path[i] != '\0') {
			if (path[i] == '/') {
				if (str == "..") {
					if(!res.empty()) res.pop_back();
					str = "";
				}
				else if (str == ".") {
					str = "";
				}
				else if (!str.empty()) {
					res.push_back(str);
					str = "";
				}			
			}
			else {
				str = str + path[i];
			}

			i++;
		}
		for (string v : res) {
			str = str + '/' + v;
		}
		return str.empty()? "/":str;
	}

	//use string stream and getline  @monaziyi
	string simplifyPath1(string path) {
		string res, tmp;
		vector<string> stk;
		stringstream ss(path);
		while (getline(ss, tmp, '/')) {
			if (tmp == "" || tmp == ".") continue;
			if (tmp == ".." && !stk.empty()) stk.pop_back();
			else if (tmp != "..") stk.push_back(tmp);
		}
		for (auto str : stk) res += "/" + str;
		return res.empty() ? "/" : res;
	}
};

int main() {
	cout << Solution().simplifyPath1("/.")<<endl;
}
