class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int bit, n = sizeof(int) * 8;
        vector<int> arr (n,0);

        for (int x:nums) {
            bit = 1;
            for (int i = 0; i < n; i++) {
                if (bit & x) {
                    if (arr[i] == 2) arr[i] = 0;
                    else arr[i]++;
                }
                if (i != n - 1) bit = bit << 1;
            }
        }

        int ans = 0;
        bit = 1;
        for (int i = 0; i < n; i++) {
            if (arr[i]) {
                ans += bit;
            }

            if (i != n - 1) bit = bit << 1;
        }
        return ans;
    }
};