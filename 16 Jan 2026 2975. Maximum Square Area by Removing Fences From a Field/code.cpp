class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& h, vector<int>& v) {
        h.push_back(1);
        v.push_back(1);
        v.push_back(n);
        h.push_back(m);
        sort(h.begin(),h.end());
        sort(v.begin(),v.end());
        int md=1e9+7;
        long long res=0,l=0;
        if(m==n)return (m-1)*(n-1);
        set<int>s1,s2;   
        for(int i=0;i<h.size()-1;i++){
            for(int j=i+1;j<h.size();j++){
                s1.insert(h[j]-h[i]);
            }
        }
        for(int i=0;i<v.size()-1;i++){
            for(int j=i+1;j<v.size();j++){
                if(s1.count(v[j]-v[i])){
                    if(res<v[j]-v[i])res=v[j]-v[i];
                    l=1;
                }
            }
        }
        
        return l?(res*res)%md:-1;
    }
};