#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>


using namespace std;

//Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
	public:
		vector<Interval> merge(vector<Interval>& intervals) {
			if (intervals.size() < 2) return intervals;
			sort(intervals.begin(), intervals.end(), [](Interval a, Interval b) {return a.start < b.start; });
			vector<Interval> ans;
			ans.push_back(intervals[0]);
			for (int i = 1; i < intervals.size(); i++) {
				if (ans.back().end < intervals[i].start) {
					ans.push_back(intervals[i]);
				}
				else {
					ans.back().end = max(ans.back().end, intervals[i].end);
				}
			}
			return ans;
		}
	};
int main() {
	vector<Interval> a = { Interval(1,2),Interval(3,4),Interval(5,6),Interval(2,7),Interval(8,10),Interval(15,18),Interval(0,19) };
	vector<Interval> b = Solution().merge(a);
}
