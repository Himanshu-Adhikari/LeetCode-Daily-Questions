class Solution:
    
    def countTrapezoids(self, points: List[List[int]]) -> int:
        m={}
        md=10**9+7
        n=len(points)
        for a,b in points:
            m[b]=m.get(b,0)+1

        res=0
        pr=0
        for b in m.values():
            if(b<2):continue
            lines=(b*(b-1))//2
            res=(res+pr*lines)%md
            pr=(pr+lines)%md
        return res