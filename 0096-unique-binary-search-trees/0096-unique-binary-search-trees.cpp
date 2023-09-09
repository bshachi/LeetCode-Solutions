class Solution {
public:
    int numTrees(int n) {
        vector<int> ans;
        ans.push_back(1);
        ans.push_back(1);
        for (int i = 2; i <= n; i++) {
            int count = 0;
            for (int j = 1; j <= i; j++) {
                count += ans[j-1]*ans[i-j];
            }
            ans.push_back(count);
        }
        return ans[n];
    }
};