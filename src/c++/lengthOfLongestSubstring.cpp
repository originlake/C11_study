#include <iostream>
#include <string>
#include <map>

using namespace std;



class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		if (s.size() < 2) return s.size();
		string a;
		a.push_back(s[0]);
		int i = 1;
		int max = 0;
		while (i < s.length()) {
			if (a.find(s[i]) == -1) {
				a.push_back(s[i]);
				i++;
				max = a.size()>max ? a.size() : max;
			}
			else {
				a.erase(0,1);
			}
		}
		return max;
	}
};
int main() {
	string s = "abcabcbb";
	cout << Solution().lengthOfLongestSubstring(s) << endl;
}
