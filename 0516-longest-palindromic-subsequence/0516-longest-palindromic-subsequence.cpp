class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        if (n == 1) return 1;
        vector<vector<int>> dp = {vector<int> (n, 0), vector<int> (n, 1), vector<int> (n)};

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n - i; j++) {
                if (s[j] == s[j+i]) dp[2][j] = 2 + dp[0][j+1];
                else dp[2][j] = max(dp[1][j], dp[1][j+1]);
                dp[0][j] = dp[1][j];
                dp[1][j] = dp[2][j];
            }
        }

        return dp[2][0];
    }
};