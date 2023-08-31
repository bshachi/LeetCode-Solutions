class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> charCount (26, 0);
        for (char c:s) charCount[c - 'a']++;
        for (char c:t) charCount[c - 'a']--;
        for (int x:charCount) if (x) return false;
        return true;
    }
};