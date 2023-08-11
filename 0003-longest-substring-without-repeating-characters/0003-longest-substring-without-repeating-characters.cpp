class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), max = 0, j;
        if (n == 0) return 0;

        for (int i = 0; i < n; i++) {
            unordered_map<char, int> mp;
            mp.clear();
            mp[s[i]]++;

            j = i+1;
            while (j < n && !mp[s[j]]) {
                mp[s[j]]++;
                j++;
            }

            //if (j == n) j++;
            if (max < j - i) max = j - i;
        }


        return max;
    }
};

// ab

// i - a
// j - b
// j = 2
