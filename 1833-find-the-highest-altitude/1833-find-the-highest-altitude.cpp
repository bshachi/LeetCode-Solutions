class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int val = 0, ans = 0;
        for (int x:gain) {
            val += x;
            if (val > ans) ans = val;
        }
        return ans;
    }
};