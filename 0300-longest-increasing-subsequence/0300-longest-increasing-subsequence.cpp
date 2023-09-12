class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> memo (n , 1);

        for (int i = n-2; i >= 0; i--) {
            for (int j = i+1; j < n; j++) {
                if (nums[j]>nums[i]) memo[i] = max(memo[i], memo[j] + 1);
            }
        }

        int ans = memo[0];
        for (int x:memo) ans = max(x, ans);
        // for (int x:memo) cout<<x<<" ";
        return ans;
    }
};