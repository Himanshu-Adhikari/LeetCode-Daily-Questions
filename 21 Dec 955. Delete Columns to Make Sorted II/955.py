class Solution:
    def minDeletionSize(self, strs: List[str]) -> int:
       res=0
       n,m=len(strs),len(strs[0])
       f=0
       v=[0]*n
       for j in range(0,m):
        f=1
        pr=v[:]
        for i in range(0,n):
            v[i]=v[i]*26+(ord(strs[i][j])-97)
        p=0
        for i in range(0,n):
            if(v[i]<p):
                f=0
                break
            p=v[i]
        if(not f):
            res+=1
            v=pr[:]
       return res 