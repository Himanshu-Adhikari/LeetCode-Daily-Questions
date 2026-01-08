class Solution:
    def maxDotProduct(self, nums1: List[int], nums2: List[int]) -> int:
        n,m=len(nums1),len(nums2)
        if(max(nums1)<0 and min(nums2)>=0):return min(nums2)*max(nums1)
        if(max(nums2)<0 and min(nums1)>=0):return min(nums1)*max(nums2)
        memo={}
        @cache
        def rec(i , j):
            if(i==n or j==m):return 0
            if((i,j) in memo):return memo[(i,j)]
            curr=max(rec(i+1,j+1),rec(i+1,j),rec(i,j+1))
            curr=max(rec(i+1,j+1)+nums1[i]*nums2[j],curr)
            memo[(i,j)]=curr
            return curr
        return rec(0,0)