class Solution {
public:
    int findMin(vector<int>& nums) {
        int first = nums[0], n = nums.size();
        if (first <= nums[n - 1]) return first;
        
        int start = 0, end = n - 1, mid;
        while (start < end) {
            mid = (start + end) / 2;
            if (nums[mid] > nums[start]) start = mid;
            else end = mid;
        }

        return nums[start + 1];

    }
};