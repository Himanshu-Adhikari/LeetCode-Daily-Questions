class Solution:
    def maxMatrixSum(self, matrix: List[List[int]]) -> int:
        n,m=len(matrix),len(matrix[0])
        mni,mnj=0,0
        for i in range(n):
            for j in range(m):
                if(abs(matrix[i][j]) <abs(matrix[mni][mnj])):
                    mni,mnj=i,j
        cn=sum(1 for i in matrix for j in i if j<0)
        sm=sum(abs(j) for i in matrix for j in i)
        if(cn%2):
            sm=sm-2*abs(matrix[mni][mnj])
        return sm
