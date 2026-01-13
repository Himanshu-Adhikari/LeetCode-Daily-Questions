class Solution:
    def separateSquares(self, squares: List[List[int]]) -> float:
        l,r=0,max(y+z for x,y,z in squares)
        res=0
        while(abs(l-r)>(10**(-5))):
            m=(l+r)/2
            fa,sa=0,0
            for x,y,h in squares:
                if(y>=m):
                    fa+=(h*h)
                elif ((y+h)<m):
                    sa+=(h*h)
                else:
                    fa+=((y+h-m)*h)
                    sa+=(m-y)*h
            if(fa>sa):
                l=m
            else:
                r=m
        return r