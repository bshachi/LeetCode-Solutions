class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int ans = distance(nums.begin(), lower_bound(nums.begin(),nums.end(), target));
        return ans;
    }
};