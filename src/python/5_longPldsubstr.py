class Solution:
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        substr = ''
        for i in range(len(s)):
            #aba
            l = 1
            tmpstr = s[i]
            while i-l>=0 and i+l<len(s) and s[i-l]==s[i+l]:
                tmpstr = s[i - l] + tmpstr + s[i + l]
                l+=1
            substr = tmpstr if len(tmpstr) > len(substr) else substr
            #aa
            l = 1
            tmpstr = ''
            while i-l+1 >= 0 and i+l<len(s) and s[i-l+1]==s[i+l]:
                tmpstr = s[i - l + 1] + tmpstr + s[i + l]
                l+=1
            substr = tmpstr if len(tmpstr) > len(substr) else substr
        return substr

if __name__ == '__main__':
    print(Solution().longestPalindrome('babad'))