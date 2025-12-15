class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        #define ll long long
        ll res=0;
        int i=0,n=prices.size();
        while(i<n){
            int pr=prices[i]+1;
            ll cnt=0;
            while(i<n and pr==prices[i]+1){pr=prices[i];cnt++,i++;res+=cnt;}
        }
        return res;
    }
};