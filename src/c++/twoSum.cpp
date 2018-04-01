#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> ans;
		map<int, int> num;
		for (int i = 0; i < nums.size(); i++) {
			int toFind = target - nums[i];
			if (num.find(toFind) != num.end()) {
				ans.push_back(i);
				ans.push_back(num[toFind]);
				return ans;
			}
			num[nums[i]] = i;
		}
		return ans;
	}
};

int main() {
	int nums[3] = { 3,2,4 };
	vector<int> a(nums, nums + 3);
	vector<int> b;
	b=Solution().twoSum(a, 6);
	for (int i = 0; i <b.size() ; i++) {
		cout << b[i] << " ";
	}
	cout << endl;
	return 0;
}