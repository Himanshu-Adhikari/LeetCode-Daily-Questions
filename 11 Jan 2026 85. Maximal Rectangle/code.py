class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        if not matrix:
            return 0
        n, m = len(matrix), len(matrix[0])
        heights = [0] * m
        res = 0
        for i in range(n):
            for j in range(m):
                if matrix[i][j] == '1':
                    heights[j] += 1
                else:
                    heights[j] = 0
            print(heights)
            stack = []
            for k in range(m + 1):
                cur = heights[k] if k < m else 0
                while stack and cur < heights[stack[-1]]:
                    h = heights[stack.pop()]
                    w = k if not stack else k - stack[-1] - 1
                    res = max(res, h * w)
                stack.append(k)
        return res
