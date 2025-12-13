class Solution:
    def validateCoupons(self, code: List[str], businessLine: List[str], isActive: List[bool]) -> List[str]:
        reg=r"[A-Za-z0-9_]+"
        a=[
            (bl, cd)
            for cd, bl, act in zip(code, businessLine, isActive)
            if act
            and bl in ("electronics", "grocery", "pharmacy", "restaurant")
            and re.fullmatch(reg, cd)
        ]
        a.sort()
        return [cd for _,cd in a]