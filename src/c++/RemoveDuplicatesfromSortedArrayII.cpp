class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() < 3) return nums.size();
		int i = 2, s = 0;
		while (i + s < nums.size()) {
			nums[i] = nums[i + s];
			if (nums[i] == nums[i - 1] && nums[i - 1] == nums[i - 2]) {
				s++;
			}
			else {
				i++;
			}
		}
		return i;
	}
};
