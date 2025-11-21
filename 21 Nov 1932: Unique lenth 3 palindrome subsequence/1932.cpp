class Solution:
    def countPalindromicSubsequence(self, s: str) -> int:
        fo,lo=[-1]*26,[-1]*26
        res=0
        for i,val in enumerate(s):
            if(fo[ord(val)-97]==-1):fo[ord(val)-97]=i
            lo[ord(val)-97]=i
        for i in range(26):
            if(lo[i]-fo[i]<2):continue
            co=[0]*26
            for j in range(fo[i]+1,lo[i]):
                co[ord(s[j])-97]=1
            res+=sum(co)
        return res