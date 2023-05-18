class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs[0].size() == 0) return "";

        string temp, ans = strs[0];
        int m, n = strs.size();

        for (int i = 1; i<n; i++)
        {
            if (strs[i].size() == 0) return "";
    
            temp = "";
            if (ans[0] != strs[i][0]) return "";

            temp.push_back(strs[i][0]);
            m = min (ans.size(), strs[i].size());

            for(int j = 1; j<m; j++)
            {
                if (ans[j] == strs[i][j]) temp.push_back(strs[i][j]);
                else break;
            }

            ans = temp;
        }

        return ans;
    }
};