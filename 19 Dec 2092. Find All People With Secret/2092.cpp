// You are given an integer n indicating there are n people numbered from 0 to n - 1. You are also given a 0-indexed 2D integer array meetings where meetings[i] = [xi, yi, timei] indicates that person xi and person yi have a meeting at timei. A person may attend multiple meetings at the same time. Finally, you are given an integer firstPerson.

// Person 0 has a secret and initially shares the secret with a person firstPerson at time 0. This secret is then shared every time a meeting takes place with a person that has the secret. More formally, for every meeting, if a person xi has the secret at timei, then they will share the secret with person yi, and vice versa.

// The secrets are shared instantaneously. That is, a person may receive the secret and share it with people in other meetings within the same time frame.

// Return a list of all the people that have the secret after all the meetings have taken place. You may return the answer in any order.

class Solution {
public:
    #define ll long long
    #define pi pair<ll,int>
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int fp) {
        vector<int>res;
        vector<ll>dist(n,INT_MAX);
        dist[0]=0,dist[fp]=0;
        map<int,vector<pi>>m;
        for(auto c:meetings){
            m[c[0]].push_back({c[1],c[2]});
            m[c[1]].push_back({c[0],c[2]});}
        priority_queue<pi,vector<pi>,greater<pi>>pq;
        pq.push({0,0});
        pq.push({0,fp});
        vector<int>vis(n,0);
        while(!pq.empty()){
            auto [tm,u]=pq.top();pq.pop();
            if(vis[u])continue;
            vis[u]=1;
            for(auto [v,uv]:m[u]){
                if(dist[v]>=uv and dist[u]<=uv){
                    dist[v]=uv;
                    pq.push({dist[v],v});
                }
            }
        }
        
        for(int i=0;i<n;i++)if(dist[i]!=INT_MAX)res.push_back(i);
        return res;
    }
};