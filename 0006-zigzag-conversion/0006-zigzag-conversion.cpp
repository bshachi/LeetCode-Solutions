class Solution {
public:
    string convert(string s, int n) {
        int l = s.size();
        if (n == 1 or n >= l) return s;
        string ans = "";


        for (int i = 0; i < l; i += 2*n - 2) ans.push_back(s[i]);

        for (int r = 1; r < n-1; r++) {
            ans.push_back(s[r]);
            for (int i = 2*n - 2; i - r < l; i += 2*n - 2) {
                ans.push_back(s[i - r]);
                if (i + r < l) ans.push_back(s[i + r]);
            }
        }

        for (int i = n - 1; i < l; i += 2*n - 2) ans.push_back(s[i]);
        
        return ans;
    }
};