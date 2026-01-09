class Solution {
public:
    TreeNode*rec(TreeNode*a,TreeNode*b,TreeNode*rt){
        if(!rt || rt==a || rt==b)return rt;
        TreeNode*f=rec(a,b,rt->left),*s=rec(a,b,rt->right);
        if(!f)return s;
        if(!s)return f;
        return rt;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        TreeNode*res=root;
        vector<TreeNode*>a;
        while(!q.empty()){
            int s=q.size();
            a.clear();
            while(s--){
                auto c=q.front();
                q.pop();
                a.push_back(c);
                if(c->left)q.push(c->left);
                if(c->right)q.push(c->right);
            }
        }
        res=a[0];
        int n=a.size();
        for(int i=1;i<n;i++)res=rec(res,a[i],root);
        return res;
    }
};