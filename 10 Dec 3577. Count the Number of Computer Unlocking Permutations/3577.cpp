class Solution {
public:
    int countPermutations(vector<int>& a) {
        // int res=0;
        int n=a.size(),md=1e9+7;
        for(int i=1;i<n;i++)if(a[i]<=a[0])return 0;
        long long res=1;n--;
        while(n){
            res=(res*n)%md;n--;
        }
        return res;
    }
};