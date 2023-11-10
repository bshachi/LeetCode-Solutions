class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> mp;
        for (auto x:adjacentPairs) {
            mp[x[0]].push_back(x[1]); 
            mp[x[1]].push_back(x[0]); 
        }

        int prev, curr, temp;
        vector<int> ans;

        for (auto p:mp) {
            if (p.second.size() == 1) {
                prev = p.first;
                curr = p.second[0];
                break;
            }
        }

        int n = adjacentPairs.size();
        ans.push_back(prev);
        ans.push_back(curr);

        while (--n) {
            if (mp[curr][0] == prev) temp = mp[curr][1];
            else temp = mp[curr][0];
            prev = curr;
            curr = temp;
            ans.push_back(curr);
        }

        return ans;
    }
};