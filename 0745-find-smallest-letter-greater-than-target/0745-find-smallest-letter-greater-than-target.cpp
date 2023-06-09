class Solution {
public:
    char nextGreatestLetter(vector<char>& l, char t) {
        int ans = upper_bound(l.begin(), l.end(), int(t)) - l.begin();
        if (ans == l.size()) ans = 0;
        return l[ans];
    }
};