class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b){
            if(a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });

        int n = intervals.size();
        vector<int> need(n, 2);
        int ans = 0;

        while(!intervals.empty()){
            auto cur = intervals.back();
            intervals.pop_back();
            int t = need.back();
            need.pop_back();

            int s = cur[0], e = cur[1];

            for(int p = s; p < s + t; p++){
                for(int i = 0; i < (int)intervals.size(); i++){
                    if(need[i] > 0 && p <= intervals[i][1])
                        need[i]--;
                }
                ans++;
            }
        }
        return ans;
    }
};
