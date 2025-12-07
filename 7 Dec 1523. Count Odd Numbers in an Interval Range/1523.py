# Given two non-negative integers low and high. 
# Return the count of odd numbers between low and high (inclusive).
class Solution:
    def countOdds(self, low: int, high: int) -> int:
        return (high-low+1)//2 +(high%2 and low%2)
    #if start and end both are odd then add +1 