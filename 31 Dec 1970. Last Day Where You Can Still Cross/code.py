class Solution:
    def latestDayToCross(self, row: int, col: int, cells: List[List[int]]) -> int:
        l,h=0,len(cells)
        def rec(md)->bool:
            a=[[0 for _ in range(col)] for i in range(row)]
            vis = [[0]*col for _ in range(row)]
            q = deque()
            dr_ = [(-1,0), (1,0), (0,-1), (0,1)]
            for ix in range(md):
                r,c=cells[ix]
                a[r-1][c-1]=1
            for i in range(col):
                if(a[0][i]):continue
                vis[0][i]=1
                q.append([0,i])
            while(q):
                s=len(q)
                while(s):
                    r, c = q.popleft()
                    if(r==row-1):return True
                    for dr, dc in dr_:
                        nr, nc = r + dr, c + dc
                        if 0 <= nr < row and 0 <= nc < col and not vis[nr][nc] and a[nr][nc]==0:
                            vis[nr][nc] = 1
                            q.append((nr, nc))
                    s-=1
            return False
        res=0
        while(l<=h):
            m=(l+h)//2
            if(rec(m)):l=m+1
            else:h=m-1
        return h