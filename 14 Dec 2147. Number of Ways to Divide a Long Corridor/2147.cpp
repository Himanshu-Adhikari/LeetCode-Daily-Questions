class Solution {
public:
    int numberOfWays(string corridor) {
        int st=count(begin(corridor),end(corridor),'S');
        if(st%2)return 0;
        if(!st)return 0;
        long long n=corridor.size(),res=0;
        long long p=0,sf=0;
        int md=1e9+7;
        for(char c:corridor){
            if(c=='S'){
                sf++;
                if(sf==3){
                    if(p){
                        if(res!=0)res=(res*(p+1))%md;
                        else res=(p+1)%md;
                    }
                    p=0;
                    sf=1;
                }
            }
            else{
                if(sf==2){
                    p++;
                }
            }
        }
        return res==0?1:res;
    }
};