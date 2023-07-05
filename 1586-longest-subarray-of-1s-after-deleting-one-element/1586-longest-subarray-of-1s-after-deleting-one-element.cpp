class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int s = -10, e = -10, ps = -10, pe = -10;
        int ans = 0;
        bool other = false, single = false;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                ps = s;
                pe = e;

                s = i;
                while (i < n && nums[i] == 1) i++;
                e = i;
            }
            if (i != n && nums[i] != 1) other = true;

            if (e - s > ans) {
                ans = e - s; 
                single = true;
            }
            if (s == pe + 1) if (e - ps - 1 > ans) {
                ans = e - ps - 1;
                single = false;
            }
        }
        if (!other && single) ans--;
        return ans;
    }
};