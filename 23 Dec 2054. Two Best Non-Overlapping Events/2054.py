class Solution:
    def maxTwoEvents(self, a: List[List[int]]) -> int:
        a.sort(key=lambda x: x[1])
        n = len(a)
        ends = [0] * n
        pref = [0] * n
        for i, (s, e, v) in enumerate(a):
            ends[i] = e
            pref[i] = max(pref[i - 1] if i > 0 else 0, v)
        res = 0
        for s, e, v in a:
            idx = bisect_left(ends, s) - 1
            best_before = pref[idx] if idx >= 0 else 0
            res = max(res, v + best_before)
        return res
