class Solution:
    def countPartitions(self, nums: List[int]) -> int:
      res,sm=0,sum(nums)-nums[0]
      curr=nums[0]
      for i,val in enumerate(nums):
        if(i==0 or i==ne):continue
        if((sm-curr)%2==0):
            res+=1
        sm-=nums[i]
        curr+=nums[i]
      return res  