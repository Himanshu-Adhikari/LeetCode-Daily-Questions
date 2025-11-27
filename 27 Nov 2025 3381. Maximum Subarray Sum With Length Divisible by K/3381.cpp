class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        #define ll long long 
        int n=nums.size();
        map<int,ll>pre,m;
        m[0]=0;
        ll sum=0,res=LLONG_MIN;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(m.count((i+1)%k)){
                res=max(res,sum-m[(i+1)%k]);
                m[(i+1)%k]=min(m[(i+1)%k],sum);
            }
            else m[(i+1)%k]=sum;
        }
        return res;
    }
};