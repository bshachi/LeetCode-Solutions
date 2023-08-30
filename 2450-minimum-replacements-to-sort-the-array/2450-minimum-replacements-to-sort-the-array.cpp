class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size(), m = nums[n-1], temp;

        for (int i = n-2; i >= 0; i--) {
            if (nums[i] <= m) m = nums[i];
            else if (nums[i] % m == 0) ans += (nums[i]/m) - 1;
            else {
                temp = (nums[i]/m) + 1;
                m = nums[i]/temp;
                ans += temp - 1;
            }
        }
        return ans;
    }
};