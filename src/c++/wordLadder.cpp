//BFS
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<unordered_set>
using namespace std;

class Solution {
public:
	int ladderLength(string begin, string end, vector<string>& wordList) {
		unordered_set<string> dict(wordList.begin(),wordList.end());
		unordered_set<string> visited;
		visited.insert(begin);
		queue<string> q;
		q.push(begin);
		q.push("");
		int len = 1;
		while (!q.empty()) {
			string str = q.front();
			q.pop();
			if (str != "") {
				for (int i = 0; i < str.size(); i++) {
					string tmp = str;
					for (char ch = 'a'; ch <= 'z'; ch++) {
						tmp[i] = ch;
						if (dict.find(tmp) != dict.end() && tmp == end) {
							return len + 1;
						}
						if (dict.find(tmp) != dict.end() && visited.find(tmp) == visited.end()) {
							q.push(tmp);
							visited.insert(tmp);
						}
					}
				}
			}
			else {
				len++;
				if (!q.empty()) {
					q.push("");
				}
			}
			
		}
		return 0;
	}
};
int main() {
	vector<string> list{ "hot","dot","dog","lot","log","cog" };
	int n = Solution().ladderLength("hit", "cog", list);
	cout << n;
	return 0;
}
