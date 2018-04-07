#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;
class Solution {
public:
	//unordered_map(using hash)   map(using tree)
	//set(not allow duplicate)    multiset(allow duplicate)
 	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		unordered_map<string, multiset<string>> mp;
		vector<vector<string>> ans;
		for(string s:strs){
			string tmp = s;
			sort(tmp.begin(), tmp.end());
			mp[tmp].insert(s);
		}
		for (auto v : mp) {
			vector<string> a(v.second.begin(), v.second.end());
			ans.push_back(a);
		}
		return ans;
	}
};
int main() {
	vector<string> a = { "eat", "tea", "tan", "ate", "nat", "bat" };
	Solution().groupAnagrams(a);
	return 0;
}
