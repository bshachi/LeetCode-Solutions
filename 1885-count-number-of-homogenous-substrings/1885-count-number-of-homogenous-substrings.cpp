class Solution {
public:
    int countHomogenous(string s) {
        int mod = 1e9 + 7;
        int i = 0, n = s.size();
        long ans = 0;
        
        while (i < n) {
            int x = i;
            while (i < n - 1 && s[i] == s[i+1]) i++;
            x = i - x + 1;

            long count = long(x) * long(x + 1) / 2;
            count %= mod;

            ans += count;
            ans %= mod;

            i++;
        }

        return ans;
    }
};