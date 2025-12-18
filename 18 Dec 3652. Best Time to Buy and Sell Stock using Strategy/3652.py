class Solution:
    def maxProfit(self, p: List[int], s: List[int], k: int) -> int:
        n=len(p)
        pr,sp=[0]*(n+1),[0]*(n+1)
        ix=0
        for i,j in zip(p,s):
            pr[ix+1]=pr[ix]+i
            sp[ix+1]=sp[ix]+i*j
            ix+=1
        res=sp[-1]
        for i in range(0,n-k+1):
            res=max(res,sp[i]+pr[i+k]-pr[i+(k//2)]+sp[-1]-sp[i+k])
        return res