class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int ans = 0;
        for (int l:left) if (l > ans) ans = l;
        for (int r:right) if (n - r > ans) ans = n - r;
        return ans;
    }
};