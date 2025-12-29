class Solution {
public:
    bool ans = false;

    unordered_map<string, vector<char>> mp;
    unordered_set<string> bad;

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for (auto &s : allowed) {
            string key = s.substr(0, 2);
            mp[key].push_back(s[2]);
        }

        dfs(0, bottom, "");
        return ans;
    }

    void dfs(int ind, const string &cur, string nxt) {
        if (ans) return;

        if (ind == 0 && bad.count(cur)) return;

        // Finished building one level
        if (ind >= (int)cur.size() - 1) {
            // Reached top of pyramid
            if (cur.size() == 2 && nxt.size() == 1) {
                ans = true;
                return;
            }
            bad.insert(cur);
            dfs(0, nxt, "");
            return;
        }

        string key = cur.substr(ind, 2);
        if (!mp.count(key)) return;

        for (char ch : mp[key]) {
            dfs(ind + 1, cur, nxt + ch);
        }
