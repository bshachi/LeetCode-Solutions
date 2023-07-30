class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        for (int i = 1; i < n; i++) nums[i] += nums[i-1];
        
        if (nums[n-1] < target) return 0;

        int ans = lower_bound(nums.begin(), nums.end(), target) - nums.begin() + 1, t;
        if (ans == 1) return 1;

        for (int i = 0; i < n; i++) {
            t = lower_bound(nums.begin() + i + 1, 
                            nums.begin() + min(i + ans, n), 
                            target + nums[i]) - nums.begin();
            if (t < n && nums[t] - nums[i] >= target) ans = t - i;
            if (ans == 1) return 1;
        }

        return ans;
    }
};