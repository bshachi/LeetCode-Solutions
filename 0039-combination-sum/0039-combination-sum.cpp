class Solution {
public:
    vector<vector<vector<int>>> memo;
    int t;

    void build_memo() {
        for (int i = 4; i <= t; i++) {
            for (int j = i - 2; j >= 2; j--) {

                if (memo[j].empty() || memo[j][0][0] != j) continue;
                int k = i/j;
                for (int a = 1; a <= k; a++) {
                    if (memo[i - a*j].empty()) continue;
                    for (auto c:memo[i - a*j]) {
                        for(auto w:c) if (w >= j && j != i - a*j) goto gr;
                        memo[i].push_back(c);
                        for (int b = 0; b<a; b++) (*(memo[i].end() - 1)).push_back(j);
                        gr: continue;
                    }

                }
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        t = target;
        memo.resize(41);
        for (auto x:candidates) memo[x].push_back({x});
        build_memo();
        
        return memo[t];
    }
};