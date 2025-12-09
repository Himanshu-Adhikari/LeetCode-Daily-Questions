# Just check back and forth count of 2*nums[i]
class Solution:
    def specialTriplets(self, nums: List[int]) -> int:
        fr,sc={},{}
        for a in nums:sc[a]=sc.get(a,0)+1
        md,res=10**9+7,0
        for b in nums:
            sc[b]-=1
            res=(res%md+(fr.get(2*b,0)*sc.get(2*b,0))%md)%md
            fr[b]=fr.get(b,0)+1
        return res
