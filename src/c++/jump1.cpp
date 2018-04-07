#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>


using namespace std;
class Solution {
public:
	bool canJump(vector<int>& nums) {
		int i = 0;
		return myJump(nums, i);
		
	}
	bool myJump(vector<int>& nums, int i) {
		int max = i + nums[i];
		int j = i;
		for (int k = i + nums[i]; k > i; k--) {
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
			return myJump(nums, j);
		}
	}
};
int main() {
	vector<int> a = {1,2,3,2,1,0,9};
	cout << Solution().canJump(a) << endl;
}
