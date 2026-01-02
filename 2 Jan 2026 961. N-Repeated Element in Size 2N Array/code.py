class Solution:
    def repeatedNTimes(self, nums: List[int]) -> int:
        a=Counter(nums)
        for i,j in enumerate(a):
            if(a[j]==len(nums)//2):return j
