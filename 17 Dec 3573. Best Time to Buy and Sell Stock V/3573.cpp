// You are given an integer array prices where prices[i] is the price of a stock in dollars on the ith day, and an integer k.

// You are allowed to make at most k transactions, where each transaction can be either of the following:

// Normal transaction: Buy on day i, then sell on a later day j where i < j. You profit prices[j] - prices[i].

// Short selling transaction: Sell on day i, then buy back on a later day j where i < j. You profit prices[i] - prices[j].

// Note that you must complete each transaction before starting another. Additionally, you can't buy or sell on the same day you are selling or buying back as part of a previous transaction.

// Return the maximum total profit you can earn by making at most k transactions.
class Solution {
public:
#define ll long long
    ll a[1001][501][2][2];
    ll rec(int i,int n,int k,int op,int t,vector<int>&p){
        if(k<=0 or i>=n)return op?INT_MIN:0;
        if(a[i][k][op][t]!=-1)return a[i][k][op][t];
        ll curr=0;
        curr=rec(i+1,n,k,op,t,p);
        if(op){
            if(t){
                curr=max(curr,-p[i]+rec(i+1,n,k-1,0,0,p));
            }
            else{
                curr=max(curr,p[i]+rec(i+1,n,k-1,0,0,p));
            }
        }
        else{
            curr=max(curr,p[i]+rec(i+1,n,k,1,1,p));
            curr=max(curr,-p[i]+rec(i+1,n,k,1,0,p));
        }
        return a[i][k][op][t]=curr;
    }
    long long maximumProfit(vector<int>& prices, int k) {
        memset(a,-1,sizeof(a));
        return rec(0,prices.size(),k,0,0,prices);
    }
};