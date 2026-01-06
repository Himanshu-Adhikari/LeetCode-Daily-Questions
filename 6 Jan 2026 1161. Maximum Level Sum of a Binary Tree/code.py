class Solution:
    def maxLevelSum(self, root: Optional[TreeNode]) -> int:
        mp={}
        def rec(rt,lv):
            if(rt == None):return 0
            mp[lv]=mp.get(lv,0)+rt.val
            return max(rec(rt.left,lv+1),rec(rt.right,lv+1))+1
        rec(root,1)
        x,l=0,float('-inf')
        for i,j in mp.items():
            if(l<j):x,l=i,j
        return x