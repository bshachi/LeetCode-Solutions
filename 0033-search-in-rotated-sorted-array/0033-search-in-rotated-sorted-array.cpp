class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int start = 0, end = n - 1;
        int mid = n/2;
        
        if (target < nums[0]) {
            while (start <= end) {
                if (nums[mid] >= nums[0] || nums[mid] < target) start = mid + 1;
                else if (nums[mid] > target) end = mid - 1;
                else return mid;

                mid = (start + end)/2;
            }
        }
        else {
            while (start <= end) {
                if (nums[mid] > target || nums[mid] < nums[0]) end = mid - 1;
                else if (nums[mid] < target) start = mid + 1;
                else return mid;

                mid = (start + end)/2;
            }
        }

        return -1;
    }
};