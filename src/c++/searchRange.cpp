#include <iostream>
#include <string>
#include <conio.h>
#include <vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		if (nums.empty()) return vector<int>{-1, -1};
		vector<int> ans;
		int n = nums.size();
		int i = 0, j = n - 1, k = -1, m;
		while (i <= j) {
			m = (i + j) / 2;
			if (nums[m] == target) {
				k = m;
				break;
			}
			else if (nums[m] < target) {
				i = m+1;
			}
			else {
				j = m - 1;
			}
		}
		if (k == -1) return vector<int>{-1, -1};
		else {
			i = k; 
			j = k;
			while (i - 1 >= 0 && nums[k] == nums[i - 1]) {
				i--;
			}
			while (j + 1 < n&&nums[k] == nums[j + 1]) {
				j++;
			}
			ans.push_back(i);
			ans.push_back(j);
		}
		return ans;
	}
};
int main() {
	vector<int> a = {1,1,2,3,3,4,4,5,5,5,5,5,6,7,8,9,11 };
	vector<int> b = Solution().searchRange(a, 1);
	for (int i = 0; i < b.size(); i++) {
		cout << b[i] << " ";
	}
	return 0;
}
