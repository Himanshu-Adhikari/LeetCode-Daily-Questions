class Solution:
    def maxProduct(self, root: Optional[TreeNode]) -> int:
        def rec(root):
            if(root is None):return 0
            return root.val+rec(root.left)+rec(root.right)
        sm=rec(root)
        res=0
        def rec2(root):
            nonlocal res
            if(root is None):return 0
            lft=rec2(root.left)
            rht=rec2(root.right)
            res=max(res,(sm-rht)*rht,(sm-lft)*lft)
            return root.val+lft+rht
        rec2(root)
        return res%(10**9 +7)