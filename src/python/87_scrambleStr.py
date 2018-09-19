class Solution:
    def isScramble(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: bool
        """
        # for elem in set(a):
        #     a.count(elem) == b.count(elem)

        if s1 == s2:
            return True
        for elem in set(s1):
            if s1.count(elem) != s2.count(elem):
                return False
        n = len(s1)
        for i in range(1,n):
            if self.isScramble(s1[0:i],s2[0:i]) and self.isScramble(s1[i:n],s2[i:n]):
                return True
            if self.isScramble(s1[0:i],s2[n-i:n]) and self.isScramble(s1[i:n],s2[0:n-i]):
                return True
        return False

if __name__ == '__main__':
    print(Solution().isScramble('abc','bca'))
