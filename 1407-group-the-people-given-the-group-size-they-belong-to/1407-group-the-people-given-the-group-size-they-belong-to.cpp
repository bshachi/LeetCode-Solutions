class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& g) {
        unordered_map<int, vector<vector<int>>> mp;
        vector<vector<int>> ans;

        int n = g.size();
        for (int i = 0; i < n; i++) {
            if (mp[g[i]].empty() || mp[g[i]][mp[g[i]].size()-1].size() == g[i]) {
                mp[g[i]].push_back({});
            }
            mp[g[i]][mp[g[i]].size()-1].push_back(i);
        }

        for (auto b:mp) {
            for (auto x:b.second) {
                ans.push_back(x);
            }
        }

        return ans;
    }
};