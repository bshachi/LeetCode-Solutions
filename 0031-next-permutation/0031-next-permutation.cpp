class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        auto i = nums.end() - 1;
        while (i > nums.begin() && *i <= *(i - 1)) i--;

        if (i == nums.begin()) {
            sort(nums.begin(), nums.end());
            return;
        }

        i--;
        int m_index, temp, m = INT_MAX;
        for (int j = distance(nums.begin(), i); j < nums.size(); j++) {
            if (nums[j] > *i && nums[j] < m) {
                m = nums[j];
                m_index = j;
            }
        }

        temp = *i;
        *i = m;
        nums[m_index] = temp;

        i++;
        sort(i, nums.end());
    }
};