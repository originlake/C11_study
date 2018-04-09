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
//bits manipulation @jianchao.li.fighter
class Solution1 {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int num_subset = pow(2, nums.size());
		vector<vector<int> > res(num_subset, vector<int>());
		for (int i = 0; i < nums.size(); i++)
			for (int j = 0; j < num_subset; j++)
				if ((j >> i) & 1)
					res[j].push_back(nums[i]);
		return res;
	}
};
class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> res;
		vector<int> ans;
		mySubsets(res, nums, ans, 0);
		return res;
	}
	void mySubsets(vector<vector<int>> &res, vector<int>& nums,vector<int> &ans, int i) {
		if (i == nums.size()) {
			res.push_back(ans);
		}
		else {
			mySubsets(res, nums, ans, i + 1);
			ans.push_back(nums[i]);
			mySubsets(res, nums, ans, i + 1);
			ans.pop_back();
		}
		
	}
};

int main() {
	vector<int> a = { 1,2,3 };
	vector<vector<int>> b = Solution1().subsets(a);
	return 0;
}
