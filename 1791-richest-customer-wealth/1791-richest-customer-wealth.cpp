class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxi = INT_MIN, sum;
        for (auto x:accounts) {
            sum = 0;
            for (auto m:x) sum += m;
            maxi = max(sum, maxi);
        }

        return maxi;
    }
};