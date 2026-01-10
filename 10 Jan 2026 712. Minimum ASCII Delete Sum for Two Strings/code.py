class Solution:
    def minimumDeleteSum(self, s1: str, s2: str) -> int:
        n, m = len(s1), len(s2)
        a = [[0] * (m + 1) for _ in range(n + 1)]
        for i in range(n - 1, -1, -1):
            a[i][m] = a[i + 1][m] + ord(s1[i])
        for j in range(m - 1, -1, -1):
            a[n][j] = a[n][j + 1] + ord(s2[j])
        for i in range(n - 1, -1, -1):
            for j in range(m - 1, -1, -1):
                if s1[i] == s2[j]:
                    a[i][j] = a[i + 1][j + 1]
                else:
                    a[i][j] = min(
                        ord(s1[i]) + a[i + 1][j],
                        ord(s2[j]) + a[i][j + 1]
                    )
        return a[0][0]
