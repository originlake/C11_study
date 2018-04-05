#include <iostream>
#include <algorithm>
#include <string>
#include <conio.h>
#include <vector>
#include <map>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
//backtracking;
class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		vector<vector<int>> ans;
		vector<int> one;
		myCombinationSum(candidates, ans, one, target, 0);
		return ans;
	}
	void myCombinationSum(vector<int>& candidates, vector<vector<int>> &ans, vector<int> &one, int target, int l) {
		if (target == 0) {
			ans.push_back(one);
		}
		for (int i = l; i<candidates.size() && candidates[i] <= target; i++) {
			one.push_back(candidates[i]);
			int count = 1;
			while (i + count < candidates.size() && candidates[i + count] <= target && candidates[i] == candidates[i + count]) {
				count++;
				one.push_back(candidates[i]);
			}
			myCombinationSum(candidates, ans, one, target - count * candidates[i], i + count);
			while (count > 0) {
				one.pop_back();
				count--;
			}
		}
	}
};
int main() {
	vector<int> c = { 10, 1, 2, 7, 6, 1, 5 };
	vector<vector<int>> a = Solution().combinationSum(c, 8);
}
