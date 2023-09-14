class Solution {
private:
    unordered_map<string,vector<pair<string,bool>>> mp;
    int ans_size;
    
    bool dfs(string s, vector<string>& ans) {
        if (ans.size() == ans_size) return true;

        int i = 0;
        while (i < mp[s].size() && mp[s][i].second) i++;

        for (; i < mp[s].size(); i++) {
            if (mp[s][i].second) continue;

            mp[s][i].second = true;
            ans.push_back(mp[s][i].first);

            if (dfs(mp[s][i].first, ans)) return true;

            ans.pop_back();
            mp[s][i].second = false;
        }
        return false;
    }

public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        ans_size = tickets.size() + 1;

        for (auto ticket:tickets) {
            mp[ticket[0]].push_back({ticket[1], false});
        }

        for (auto it = mp.begin(); it != mp.end(); it++) {
            sort(it->second.begin(), it->second.end());
        }

        vector<string> ans = {"JFK"};
        dfs("JFK", ans);

        return ans;
    }
};