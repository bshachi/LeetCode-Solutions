class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        vector<int> rmax;
        vector<int> cmax;
        int n = grid.size();
        for (int i = 0; i < n; i++) {
            int cm = grid[0][i], rm = grid[i][0];
            for (int j = 0; j < n; j++) {
                rm = max(grid[i][j], rm);
                cm = max(grid[j][i], cm);
            }
            rmax.push_back(rm);
            cmax.push_back(cm);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ans += min(rmax[i], cmax[j]) - grid[i][j];
                //cout<<min(rmax[i], cmax[j])<<" ";
            }
            //cout<<endl;
        }

        return ans;
    }
};