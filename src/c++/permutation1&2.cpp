#include <cstdlib>
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
//permute 1
//class Solution {
//public:
//	vector<vector<int>> permute(vector<int>& nums) {
//		sort(nums.begin(), nums.end());
//		vector<vector<int>> ans;
//		vector<int> res;
//		myPermute(nums, ans, res);
//		return ans;
//	}
//	void myPermute(vector<int> &nums, vector<vector<int>> &ans, vector<int> &res) {
//		if (res.size() == nums.size()) {
//			ans.push_back(res);
//		}
//		for (int i = 0; i < nums.size(); i++) {
//			if (find(res.begin(), res.end(), nums[i]) == res.end()) {
//				res.push_back(nums[i]);
//				myPermute(nums, ans, res);
//				res.pop_back();
//			}
//		}
//	}
//};
class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> ans;
		vector<int> res;
		vector<int> index;
		myPermute(nums, ans, res,index);
		return ans;
	}
	void myPermute(vector<int> &nums, vector<vector<int>> &ans, vector<int> &res, vector<int> index) {
		if (res.size() == nums.size()) {
			ans.push_back(res);
		}
		int i = 0;
		while (i < nums.size()) {
			if (find(index.begin(), index.end(), i) != index.end()) {
				i++;
				continue;
			}
			res.push_back(nums[i]);
			index.push_back(i);
			myPermute(nums, ans, res, index);
			res.pop_back();
			index.pop_back();
			i++;
			while (i > 0 &&i<nums.size()&& nums[i] == nums[i - 1]) {
				i++;
			}
		}
	}
};
int main() {
	vector<int> a = { 1,1,1 };
	vector<vector<int>> ans = Solution().permuteUnique(a);
	return 0;
}
