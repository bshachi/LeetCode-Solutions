class Solution {
public:

    long long ans;

    void solve(int start, int end, vector<vector<int>>& indices) {
        int n = indices.size();
        if (n<2) return;
        int m1 = indices[0][0], m2;
        bool mini = indices[0][1];

        for (int i = 1; i<n; i++) {
            if (indices[i][1] == not(mini)) {
                m2 = indices[i][0];
                ans += (m1 - start + 1) * (end - m2 + 1);
                start = m1 + 1;
                m1 = m2;
                mini = not(mini);
            }
            else m1 = indices[i][0];
        }
    }

    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        ans = 0;
        vector<vector<int>> indices;
        int start = 0, n = nums.size();

        for (int i = 0; i<n; i++) {
            if (nums[i] == minK) indices.push_back({i, 0});
            if (nums[i] == maxK) indices.push_back({i, 1});

            if (nums[i]>maxK || nums[i]<minK) { 
                solve(start, i-1, indices);
                indices.clear();
                start = i+1;
            }
            else if (i == n-1) {
                solve(start, i, indices);
                indices.clear();
            }
        }

        return ans;
    }
};