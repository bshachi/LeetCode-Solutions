class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        nums[n-1] =  0;
        for (int i = n - 2; i >= 0; i--) {
            int temp = nums[i+1];
            for (int j = 2; j <= nums[i] && j+i < n; j++) temp = min(temp, nums[i + j]);
            nums[i] = temp + 1;
        }
        return nums[0];
    }
};