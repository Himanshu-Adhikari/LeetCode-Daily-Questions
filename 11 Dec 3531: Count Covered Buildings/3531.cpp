class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        int res=0;
        n++;
        vector<int>rm(n,-1),rmi(n,n),cm(n,-1),cmi(n,n);
        for(auto &c:buildings){
            rm[c[0]]=max(rm[c[0]],c[1]);
            rmi[c[0]]=min(rmi[c[0]],c[1]);
            cm[c[1]]=max(cm[c[1]],c[0]);
            cmi[c[1]]=min(cmi[c[1]],c[0]);
        }
        for(auto c:buildings){
            int mxr=rm[c[0]],mnr=rmi[c[0]];
            int mxc=cm[c[1]],mnc=cmi[c[1]];
            int x=c[1],y=c[0];
            if(mxr>x && mnr<x && mxc>y && mnc<y)res++;
        }
        return res;
    }
};