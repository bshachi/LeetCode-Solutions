class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> color (3, 0);
        int n = nums.size();
        for (int c:nums) color[c]++;
        color[1] += color[0];
        color[2] += color[1];

        int i = 0;
        for (; i < color[0]; i++) nums[i] = 0;
        for (; i < color[1]; i++) nums[i] = 1;
        for (; i < color[2]; i++) nums[i] = 2;
    }
};