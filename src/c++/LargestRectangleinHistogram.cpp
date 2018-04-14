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
class Solution {
////TLE
//public:
//	int largestRectangleArea(vector<int>& heights) {
//		vector<bool> pos(heights.size(), 0);
//		return subLongestRA(heights, pos, 0, heights.size()-1);
//	}
//	int subLongestRA(vector<int> &heights, vector<bool> &pos, int l, int r) {
//		if (l == r) {
//			pos[l] = 1;
//			return heights[l];
//		}
//		if (r < l) return 0;
//		int minh = INT_MAX;
//		for (int i = l; i <= r; i++) {
//			if (!pos[i] && heights[i] < minh ) {		
//				minh = heights[i];
//			}
//		}
//		for (int i = l; i <= r; i++) {
//			if (heights[i] == minh) {
//				pos[i] = 1;
//			}
//		}
//		int i = 0;
//		int maxh = minh * (r - l + 1);
//		while (i < pos.size()) {
//			if (!pos[i]) {
//				l = i++;
//				while (i < pos.size() && !pos[i]) {
//					i++;
//				}
//				r = i - 1;
//				maxh = max(maxh, subLongestRA(heights, pos, l, r));
//			}
//			else {
//				i++;
//			}
//		}
//		return maxh;
//	}

public:
	//idea of stack
	int largestRectangleArea(vector<int>& heights) {
		heights.push_back(0);
		heights.insert(heights.begin(), 0);
		vector<int> index;
		int maxh = 0;
		int l, r, len;
		for (int i = 0; i < heights.size(); i++) {
			if (index.empty() || heights[index.back()] <= heights[i]) {
				index.push_back(i);
			}
			else {
				while (!index.empty() && heights[index.back()] > heights[i]) {
					r = index.back();
					l = r;
					index.pop_back();
					while (!index.empty() && heights[index.back()] == heights[r]) {
						index.pop_back();
					}
					len = i - index.back()-1;
					maxh = max(maxh, heights[r] * len);
				}
				index.push_back(i);
			}
		}
		return maxh;
	}
};
