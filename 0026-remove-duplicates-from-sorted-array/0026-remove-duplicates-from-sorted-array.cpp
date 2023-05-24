class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int curr = 0;
        for (int i = 1; i<n; i++) {
            if (nums[i] == nums[curr]) continue;
            curr++;
            nums[curr] = nums[i];
        }

        return curr+1;
    }
};