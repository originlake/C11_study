class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		if (nums.empty()) {
			return 1;
		}
		int l = 0, r = nums.size()-1,tmp;
		//swap negative integer to the end
		while (l < r) {
			if (nums[r] <= 0) {
				r--;
			}
			else if (nums[l] > 0) {
				l++;
			}
			else {
				tmp = nums[l];
				nums[l] = nums[r];
				nums[r] = tmp;
			}
		}
		if (nums[0] <= 0) {
			return 1;
		}
    //Mark the positive integer whose value is in index as negative
		for (int i = 0; i < l + 1; i++) {
			if (abs(nums[i]) < l + 2) {
				nums[abs(nums[i])-1] = -abs(nums[abs(nums[i])-1]);
			}
		}
		for (int i = 0; i < l + 1; i++) {
			if (nums[i] > 0){
				return i+1;
			}
		}
		return l + 2;
	}
};
