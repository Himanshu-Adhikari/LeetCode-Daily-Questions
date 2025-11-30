class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n=nums.size(),res=INT_MAX;
        map<int,int>m;
        #define ll long long
        ll sm=accumulate(begin(nums),end(nums),0ll);
        if(sm%p==0)return 0;
        ll cr=0,req=sm%p;
        m[0]=-1;
        for(int i=0;i<n;i++){
            cr=(cr+nums[i])%p;
            if(nums[i]%p == req)return 1;
            if(cr==req)res=min(res,i+1);
            if(m.count((cr-req+p)%p)){
                res=min(res,i-m[(cr-req+p)%p]);
            }
            m[cr]=i;
        }
        if(res==n)return -1;
        return res==INT_MAX?-1:res;
    }
};