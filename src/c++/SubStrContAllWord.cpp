#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<unordered_set>
#include<unordered_map>
using namespace std;

class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		vector<int> res;
		unordered_map<string, int> dict;
		unordered_map<string, int> winDict;
		if ((int)words.size() == 0) {
			return res;
		}
		int wordLen = words[0].length();
		int dictLen = (int)words.size();
		for (string word : words) {
			dict[word] += 1;
			if (word.length() != wordLen) {
				return res;
			}
		}

		for (int i = 0; i < (int)s.size() - wordLen * dictLen; i++) {
			unordered_map<string, int> myDict(dict);
			for (int j = 0; j < dictLen; j++) {
				string word(s, i + j * wordLen, wordLen);
				if (dict.find(word) == dict.end()) {
					break;
				}
				myDict[word]--;
			}
			if (dict_check(myDict)) {
				res.push_back(i);
			}
		}

		return res;
	}
	bool dict_check(unordered_map<string, int>& dict) {
		for (auto i : dict) {
			if (i.second != 0) {
				return false;
			}
		}
		return true;
	}
};
int main() {
	
}
