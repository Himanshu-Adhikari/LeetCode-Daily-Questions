class Solution:
    def maxSumDivThree(self, nums: List[int]) -> int:
        sm=sum(nums)
        nums.sort()
        a,b=[i for i in nums if i%3==1],[i for i in nums if i%3==2]
        def rec(a, b):
            fc = sm - a[0] if a else 0
            sc = sm - b[0] - b[1] if len(b) > 1 else 0
            return max(fc, sc)
        if(sm%3==1):
            sm=rec(a,b)
        elif(sm%3==2):
            sm=rec(b,a)
        return sm