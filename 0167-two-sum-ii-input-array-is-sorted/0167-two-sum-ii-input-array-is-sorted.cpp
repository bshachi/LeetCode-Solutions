class Solution {
public:
    vector<int> twoSum(vector<int>& nu, int t) {
        int n = nu.size();
        int l = 0, r = n - 1;

        while (true) {
            if (nu[l] + nu[r] == t) return {l + 1, r + 1};
            if (nu[l] + nu[r] > t) {
                r = lower_bound(nu.begin() + l + 1, nu.begin() + r, t - nu[l]) - nu.begin();
                if (nu[l] + nu[r] == t) return {l + 1, r + 1};
                r--;
            }
            if (nu[l] + nu[r] < t) {
                l = lower_bound(nu.begin() + l + 1, nu.begin() + r, t - nu[r]) - nu.begin();
            }
        }
    }
};