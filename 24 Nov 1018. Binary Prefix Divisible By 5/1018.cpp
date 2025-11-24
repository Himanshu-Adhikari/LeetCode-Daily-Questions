class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> res;
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum = sum * 2 + nums[i];
            res.push_back(sum % 5 == 0);
            sum %= 5;
        }
        return res;
    }
};
