class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        for (int i = 1; i <= 9; i++) {
            for (int x:nums1) {
                if (x == i) {
                    for (int y:nums2) {
                        if (y == i) return i;
                    }
                }
            }
        }
        int min1 = 10, min2 = 10;
        for (int x:nums1) if (x < min1) min1 = x;
        for (int x:nums2) if (x < min2) min2 = x;

        if (min1 > min2) {
            int temp = min1;
            min1 = min2;
            min2 = temp;
        }

        return min1*10 + min2;

    }
};