class Solution {
public:
    int candy(vector<int>& r) {
        int n = r.size();
        vector<int> memo (n, 1);
        
        for (int i = 1; i < n; i++) {
            if (r[i] > r[i-1]) memo[i] = memo[i-1]+1;
        }

        for (int i = n-2; i >= 0; i--) {
            if (r[i] > r[i+1]) memo[i] = max(memo[i+1]+1, memo[i]);
        }

        int ans = 0;
        for (int x:memo) ans+=x;
        return ans;
    }
};