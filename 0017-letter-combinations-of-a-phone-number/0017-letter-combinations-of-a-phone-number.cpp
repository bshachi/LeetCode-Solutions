class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (not(digits.size())) return ans;

        int n;
        string letters[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        ans.push_back("");

        for(char x:digits) {
            n = ans.size();
            for (int i = 0; i<n; i++) {
                for (char y:letters[int(x) - 50]) ans.push_back(ans[0] + y);
                ans.erase(ans.begin());
            }
        }

        return ans;
    }
};