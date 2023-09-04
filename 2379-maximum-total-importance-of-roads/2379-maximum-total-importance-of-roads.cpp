class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> noOfRoads (n, 0);
        for (auto r:roads) {
            noOfRoads[r[0]]++;
            noOfRoads[r[1]]++;
        }

        sort(noOfRoads.begin(), noOfRoads.end());

        long long ans = 0;
        for (int i = 0; i < n; i++) ans += ((long long) noOfRoads[i]) * (i+1);

        return ans;
    }
};