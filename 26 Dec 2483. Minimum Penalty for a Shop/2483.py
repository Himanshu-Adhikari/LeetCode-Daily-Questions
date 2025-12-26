class Solution:
    def bestClosingTime(self, cust: str) -> int:
        curr=sum(1 for i in cust if i=='Y') 
        res,tot=0,curr
        for idx,i in enumerate(cust):
            if(i=='N'):curr+=1
            else:curr-=1
            if(tot>curr):
                tot,res=curr,idx+1
        return res