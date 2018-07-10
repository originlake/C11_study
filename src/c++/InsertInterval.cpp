// reload is faster than function
bool operator<(const Interval& i1, const Interval& i2)
{
	return i1.start < i2.start;
}

class Solution{
public:

	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		vector<Interval> res;
		intervals.push_back(newInterval);
 		sort(intervals.begin(), intervals.end());
		size_t n = intervals.size();
		res.push_back(intervals[0]);
		for (int i = 1; i < n; i++) {
			if (intervals[i].start > res.back().end) {
				res.push_back(intervals[i]);
			}
			else {
				res.back().end = max(res.back().end, intervals[i].end);
			}
		}
		return res;
	}
};
