class Solution {
public:
    long long maxRunTime(int n, vector<int>& b) {
        #define ll long long 
        int m=b.size();
        ll l=*min_element(begin(b),end(b)),h=*max_element(begin(b),end(b));
        sort(rbegin(b),rend(b));
        h=1e16;
        auto rec=[&](ll md){
            ll ex=0;
            for(int j=n;j<m;j++){
                ex+=b[j];
            }
            for(int i=0;i<n;i++){
                if(b[i]<md){
                    if(ex+b[i]<md)return false;
                    ex-=(md-b[i]);
                }
            }
            return true;
        };
        while(l<=h){
            ll md=l+(h-l)/2;
            // cout<<md<<" ";
            if(rec(md))l=md+1;
            else h=md-1;
        }
        return h;
    }
};