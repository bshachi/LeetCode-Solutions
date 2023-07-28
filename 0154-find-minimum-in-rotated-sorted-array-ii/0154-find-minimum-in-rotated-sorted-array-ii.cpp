class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = 0;
        for (int x:nums) {
            if (x == nums[n]) continue;
            n++;
            nums[n] = x;
        }

        n++;
        if (n == 1) return nums[0];
        
        nums.resize(n);
        if (nums[n - 1] == nums[0]) {
            nums.pop_back();
            n--;
        }
        
        int first = nums[0];
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