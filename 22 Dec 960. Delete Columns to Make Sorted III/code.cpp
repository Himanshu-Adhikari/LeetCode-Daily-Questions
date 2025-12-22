class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n=strs.size(),m=strs[0].size();
        vector<int>dp(m,1);
        // if(n==1)return m-1;
        for(int i=1;i<m;i++){
            for(int j=0;j<i;j++){
                int f=1;
                for(auto c:strs){
                    if(c[j]>c[i]){f=0;break;}
                }
                if(f)dp[i]=max(dp[i],dp[j]+1);
            }
        }
        // for(int i:dp)cout<<i<<" ";
        return m-*max_element(begin(dp),end(dp));
    }
};