class Solution {
public:
    int climbStairs(int n) {
        int prev = 0, ans = 1;
        for (int i  = 0; i < n; i++) {
            ans += prev;
            prev = ans - prev;
        }
        return ans;
    }
};