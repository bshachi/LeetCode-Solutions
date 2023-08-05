class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        vector<bool> arr (n + 1, false);
        for (int x:nums) {
            if (arr[x]) return x;
            arr[x] = true;
        }

        return 0;
    }
};