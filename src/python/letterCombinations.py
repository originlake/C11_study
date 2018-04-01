class Solution:
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        ans=['']
        key=['','','abc','def','ghi','jkl','mno','pqrs','tuv','wxyz']
        for e in digits:
            e=int(e)
            if e<=1:
                continue
            l=len(ans)
            ans=ans*len(key[e])
            for i in range(len(key[e])):
                for j in range(l):
                    ans[i*l+j]+=key[e][i]
        if ans[0]=='':
            ans=[]
        return ans
print(Solution().letterCombinations('2'))
                
        