class Solution {
public:
    int smallestRepunitDivByK(int k) {
     map<int,int>m;
     int rem=1,l=1;
     while(rem%k!=0){
        int nm=rem*10+1;
        rem=nm%k;
        l++;
        if(m[rem])return -1;
        else m[rem]=1;
     }  
     return l; 
    }
};