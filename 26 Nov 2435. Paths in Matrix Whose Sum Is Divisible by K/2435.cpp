class Solution {
public:
    int numberOfPaths(vector<vector<int>>& g, int k) {
        int m=g.size(), n=g[0].size(), md=1e9+7;
        vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(n+1, vector<int>(k,0)));
        dp[1][1][g[0][0]%k]=1;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(i==1 && j==1) continue;
                for(int r=0;r<k;r++){
                    int nr=(r+g[i-1][j-1])%k;
                    dp[i][j][nr]=(dp[i][j][nr] + dp[i-1][j][r] + dp[i][j-1][r])%md;
                }
            }
        }
        return dp[m][n][0];
    }
};
