class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<string,int> mp;
        int ans = 0, n = grid.size();
        string s;

        for (auto x:grid) {
            s = "";
            for (auto y:x) {
                ostringstream ss;
                ss<<setfill('0')<<setw(5)<<hex<<y; 
                s += ss.str();
            }
            mp[s]++;
        }

        for (int j = 0; j < n; j++) {
            s = "";
            for (int i = 0; i < n; i++) {
                ostringstream ss;
                ss<<setfill('0')<<setw(5)<<hex<<grid[i][j]; 
                s += ss.str();
            }
            ans += mp[s];
        }

        return ans;
    }
};