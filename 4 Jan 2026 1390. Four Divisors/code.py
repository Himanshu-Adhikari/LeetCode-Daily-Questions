class Solution:
    def sumFourDivisors(self, nums: List[int]) -> int:
        res=0
        for i in nums:
            cnt,f=0,0
            for j in range(2,int(sqrt(i))+1):
                if(i%j==0):cnt,f=cnt+1,j
                if(cnt>1):break
            if(cnt==1):
                if(f==(i/f)):continue
                res=res+1+i+f+(i/f)
        return int(res)