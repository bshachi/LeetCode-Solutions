class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), maximum = 0, j;
        if (n == 0) return 0;

        for (int i = 0; i < n;) {
            unordered_map<char, int> mp;
            mp.clear();
            mp[s[i]] = i+1;

            j = i+1;
            while (j < n && !mp[s[j]]) {
                mp[s[j]] = j+1;
                j++;
            }

            if (j == n) return max(maximum, n - i);
            if (maximum < j - i) maximum = j - i;
            i = mp[s[j]];
        }


        return maximum;
    }
};

// ab

// i - a
// j - b
// j = 2
