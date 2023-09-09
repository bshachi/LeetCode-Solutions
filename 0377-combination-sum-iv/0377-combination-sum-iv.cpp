class Solution {
public:
    int cs(vector<int>& nums, int target, vector<int>& memo, int n) {
        int count = 0;

        for (int i = 0; i < n && nums[i] <= target; i++) {
            if (memo[target - nums[i]] == -1) memo[target - nums[i]] = cs(nums, target - nums[i], memo, n);
            count += memo[target - nums[i]];
        }
        return count;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> memo (target+1, -1);
        int n = nums.size();
        sort(nums.begin(), nums.end());

        memo[0] = 1;

        return cs(nums, target, memo, n);
    }
};