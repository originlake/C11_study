class Solution:
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        # # use dict for counting character appearance, if cnt > 1 then left pointer move right until cnt == 1,
        # # slower because using loop to move left pointer
        # l = 0
        # maxlen = 0
        # cnt = dict()
        # for r in range(len(s)):
        #     cnt[s[r]] = cnt.get(s[r], 0)+1
        #     if cnt[s[r]] > 1:
        #         maxlen = r-l if r-l>maxlen else maxlen
        #         while cnt[s[r]] > 1:
        #             cnt[s[l]] -= 1
        #             l += 1
        # maxlen = len(s) - l if len(s) - l > maxlen else maxlen
        # return maxlen

        # improvement: using dict to save appeared character's idx, thus can find last appearance in O(1)
        l = 0
        maxlen = 0
        idx = dict()
        for r, ch in enumerate(s):
            if ch in idx and l <= idx[ch]:
                maxlen = max(r-l, maxlen)
                l = idx[ch]+1
            idx[ch]=r
        return max(maxlen, len(s)-l)

