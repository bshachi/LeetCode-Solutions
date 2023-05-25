class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0, j = nums.size() - 1;
        if (j == 0 && nums[0] == val) return 0;

        while (i < j) {
            while(j>0 && nums[j] == val) j--;
            if (j<i) return j+1;

            if (nums[i] == val) {
                nums[i] = nums[j];
                j--;
            }

            i++;
        }

        if (j == i && nums[i] == val) return j;
        return j+1;
    }
};