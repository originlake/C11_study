class Solution:
    def longestValidParentheses(self, s):
        """
        :type s: str
        :rtype: int
        """
        # # Using stack
        # stack = list()
        # mark = [0]*len(s)
        # for i in range(len(s)):
        #     if s[i] == '(':
        #         stack.append(i)
        #     elif stack:
        #         mark[i] = 1
        #         mark[stack.pop()] = 1
        #
        # cnt, maxcnt = 0, 0
        # for i in range(len(s)):
        #     if mark[i] == 0:
        #         maxcnt = max(cnt, maxcnt)
        #         cnt = 0
        #     else:
        #         cnt += 1
        # return maxcnt

        # Using dp
        if not s:
            return 0
        dp = [0 for _ in range(len(s))]
        for i in range(len(s)):
            if s[i] == '(':
                continue
            if i > 0 and s[i - 1] == '(':
                dp[i] = 2 + (dp[i-2] if i-2 >= 0 else 0)
            if i > 0 and s[i - 1] == ')' and i - dp[i - 1] -1 >= 0 and s[i - dp[i - 1] -1] == '(':
                dp[i] = dp[i - 1] + 2 + (dp[i - dp[i - 1] -2] if i - dp[i - 1] -2 >= 0 else 0)
        return max(dp)

if __name__ == '__main__':
    print(Solution().longestValidParentheses(")()())"))