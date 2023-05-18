class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> ans;
        if (questions.empty()) return 0;
        
        long long temp;
        long long prev;
        int len = questions.size();
        ans.push_back(questions[len-1][0]);

        for (int i = 1; i<len; i++)
        {
            if (questions[len-1-i][1] >= i) prev = 0;
            else prev = ans[i - 1 - questions[len-1-i][1]];

            temp = max(ans[i-1], questions[len-1-i][0] + prev);
            ans.push_back(temp);
        }

        return ans[len-1];
    }
};