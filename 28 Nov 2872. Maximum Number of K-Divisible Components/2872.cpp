class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        map<int,multiset<int>>a;
        for(auto c:edges){
            a[c[0]].insert(c[1]);
            a[c[1]].insert(c[0]);
        }
        int res=1;
        queue<int>q;
        vector<long long>b(values.begin(),values.end());
        for(auto c:a){
            if(c.second.size()==1)q.push(c.first);
        }
        while(!q.empty()){
            int c=q.front();q.pop();
            if(a[c].empty())continue;
            int p=*a[c].begin();
            b[p]+=b[c];
            b[p]%=k;
            a[p].erase(a[p].find(c));
            if(a[p].size()==1)q.push(p);
            res+=b[c]%k==0;
        }
        return res;
    }
};