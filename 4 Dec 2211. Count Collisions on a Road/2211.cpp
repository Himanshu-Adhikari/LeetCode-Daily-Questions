class Solution {
public:
    int countCollisions(string d) {
        int  n = d.size();
        int l = 0, r = n - 1;
        while (l < n and d[l] == 'L')
            l++;
        while (r >= 0 and d[r] == 'R')
            r--;
        if (l >= r)
            return 0;
        int res=r-l+1-count(begin(d)+l,begin(d)+r+1,'S');
        return res;
    }
};