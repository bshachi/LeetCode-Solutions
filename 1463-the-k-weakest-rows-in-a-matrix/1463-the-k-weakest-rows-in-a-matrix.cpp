class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>> pq;
        int n = mat.size(), m = mat[0].size();
        for (int i = 0; i < n; i++) {
            int j = 0;
            for (; j < m && mat[i][j] != 0; j++);
            pq.push({j, i});
            if (pq.size() > k) pq.pop();
        }
        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};