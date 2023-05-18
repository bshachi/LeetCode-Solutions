class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s == "") return 0;

        int m = 1, ans = 1;
        int letter_found, n = s.size();
        string current = "";
        current.push_back(s[0]);

        for (int i = 1; i<n; i++)
        {
            letter_found = -1;
            for (int j = 0; j<m; j++)
            {
                if (s[i] == current[j]) letter_found = j;
            }

            current = current.substr(letter_found + 1, m - letter_found - 1);
            current.push_back(s[i]);
            m = current.size();

            if (m > ans) ans = m;
        }

        return ans;
    }
};