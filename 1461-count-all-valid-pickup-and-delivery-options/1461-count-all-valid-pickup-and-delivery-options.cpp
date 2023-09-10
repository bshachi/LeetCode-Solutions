class Solution {
public:
    int countOrders(int n) {
        long ans = 1;
        long MOD = 1000000007;
        for (int i = 2; i <= n; i++) ans = (ans*i) % MOD;
        for (int i = 2*n - 1; i > 0; i -= 2) ans = (ans*i) % MOD;
        return ans;
    }
};