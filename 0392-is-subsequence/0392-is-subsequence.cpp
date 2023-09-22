class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = t.size(), m = s.size();
        if (m == 0) return true;

        for (int i = 0, j = 0; i < n && j < m; i++, j++) {
            while (i < n && t[i] != s[j]) i++;
            if (j == m - 1 && i < n) return true;
        }
        return false;
    }
};