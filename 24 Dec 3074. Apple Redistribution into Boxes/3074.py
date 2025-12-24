class Solution:
    def minimumBoxes(self, apple: List[int], cap: List[int]) -> int:
        sm=sum(apple)
        cap.sort(key=lambda x:-x)
        res=0
        for i,val in enumerate(cap):
            res+=val
            if(res>=sm):return i+1
        return len(cap)