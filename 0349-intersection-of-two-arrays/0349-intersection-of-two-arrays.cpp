class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> ans;

        int n = nums1.size(), m = nums2.size(), temp;
        for (int i = 0, j = 0; i < n && j < m;) {
            if (nums1[i] == nums2[j]) {
                temp = nums1[i];
                ans.push_back(temp);
                while (i < n && nums1[i] == temp) i++;
                while (j < m && nums2[j] == temp) j++;
            }

            if (j >= m) break;
            while (i < n && nums1[i] < nums2[j]) i++;
            if (i >= n) break;
            while (j < m && nums1[i] > nums2[j]) j++;
        }

        return ans;
    }
};