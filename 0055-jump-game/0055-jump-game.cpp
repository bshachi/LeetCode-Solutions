class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return true;

        for (int i = 1; i < n; i++) nums[i] = max(nums[i-1], nums[i] + i);
        for (int i = 0; i != nums[i]; i = nums[i]) if (nums[i] >= n-1) return true;

        return false;
    }
};