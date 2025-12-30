class Solution:
    def numMagicSquaresInside(self, grid: List[List[int]]) -> int:
        n, m = len(grid), len(grid[0])
        res = 0
        for i in range(n - 2):
            for j in range(m - 2):
                seen = [0] * 9
                rows , cols = [0]*3 , [0]*3
                d1 = d2 = 0
                ok = True
                for r in range(3):
                    s = 0
                    for c in range(3):
                        v = grid[i + r][j + c]
                        if v < 1 or v > 9:
                            ok = False
                            break
                        seen[v - 1] = 1
                        s += v
                        cols[c] += v
                        if r == c:
                            d1 += v
                        if r + c == 2:
                            d2 += v
                    rows[r]=s
                    if not ok:
                        break
                if ok and sum(seen) == 9 and rows[0]==rows[1]==rows[2]==cols[0] == cols[1] == cols[2] == d1 == d2 == 15:
                    res += 1
        return res
