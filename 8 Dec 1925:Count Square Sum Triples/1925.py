'''A square triple (a,b,c) is a triple where a, b, and c are integers and a2 + b2 = c2.
Given an integer n, return the number of square triples such that 1 <= a, b, c <= n.
'''

'''
Thought do n2 have sqayre of current then sqrt it then check if we get the same square and the num is <=n
'''
class Solution:
    def countTriples(self, n: int) -> int:
        res=0
        for  i in range(1,n):
            for j in range(1,n):
                sqr=i**2 + j**2
                nm=int(sqr**0.5)
                if(sqr==nm*nm and nm<=n):res+=1
        return res