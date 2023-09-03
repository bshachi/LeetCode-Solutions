class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        
        vector<vector<int>> memo (n, vector<int> (m, 1));
        for(int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (obstacleGrid[i][j]) memo[i][j] = 0;
                else if (i == 0) {
                    if (j != 0) memo[i][j] = memo[i][j-1];
                }
                else if (j == 0) memo[i][j] = memo[i-1][j];
                else memo[i][j] = memo[i][j-1] + memo[i-1][j];
                // cout<<memo[i][j]<<" ";
            }
            // cout<<endl;
        }
        return memo[n-1][m-1];
    }
};