class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        return sum(j<0 for i in grid for j in i)