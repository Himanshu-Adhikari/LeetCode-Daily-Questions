class Solution:
    def maximumHappinessSum(self, a: List[int], k: int) -> int:
        a.sort(key=lambda x:-x)
        return sum(max(a[i]-i,0) for i in range(0,k))
    