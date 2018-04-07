#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>


using namespace std;
class Solution {
public:
	int canJump(vector<int>& nums) {
		if (nums.size() <= 1) {
			return 0;
		}
		return myJump2(nums, 0, 0);
		
	}
	bool myJump(vector<int>& nums, int i, int lastmax) {
		int max = i + nums[i];
		int j = i;
		for (int k = i + nums[i]; k > lastmax; k--) {
			if (k + nums[k] > max) {
				max = k + nums[k];
				j = k;
			}
		}
		if (max >= nums.size() - 1) {
			return true;
		}
		else if (i == j) {
			return false;
		}
		else {
			return myJump(nums, j, i + nums[i]);
		}
	}

	int myJump2(vector<int>& nums, int i, int lastmax) {
		int max = i + nums[i];
		if (max >= nums.size() - 1) {
			return 1;
		}
		int j = i;
		for (int k = i + nums[i]; k > lastmax; k--) {
			if (k + nums[k] > max) {
				max = k + nums[k];
				j = k;
			}
		}
		return 1+myJump2(nums, j, i + nums[i]);
	}
};
int main() {
	vector<int> a = { 1,1,1,1,1,1,1 };
	cout << Solution().canJump(a) << endl;
}
