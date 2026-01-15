class Solution {
public:
    int rec(vector<int>& nums) {
        int s=1,cnt=1;
        for (int i=0;i<nums.size() - 1;i++) {
            if (nums[i + 1]-nums[i]== 1) {
                cnt++;
            } else {
                s=max(s,cnt + 1);
                cnt=1;
            }
        }
        s = max(s,cnt+1);
        return s;
    }
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        int hc=rec(hBars),vc=rec(vBars);
        int a=min(hc,vc);
        return a*a;
    }
};
