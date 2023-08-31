class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 1;

        int curr = 0;
        bool second = true;

        for (int i = 1; i<n; i++) {
            if (nums[i] != nums[curr]) second = false;
            else if (!second) continue;
            
            second = !second;
            curr++;
            nums[curr] = nums[i];
        }

        return curr+1;
    }
};