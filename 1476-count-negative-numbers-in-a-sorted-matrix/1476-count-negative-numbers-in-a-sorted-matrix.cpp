class Solution {
public:
    int countNegatives(vector<vector<int>>& v) {
        int m = v.size();
        int n = v[0].size();
        int ind, ans = 0;

        for (int i = m-1; i >= 0; i--) {
            ind = upper_bound(v[i].begin(), v[i].end(), 0, greater<int>()) - v[i].begin();
            if (ind == n) break;
            ans += n - ind;
        }

        return ans;
    }
};