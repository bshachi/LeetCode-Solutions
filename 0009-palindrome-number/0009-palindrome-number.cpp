class Solution {
public:
    bool isPalindrome(int x) {
        string a = to_string(x);
        int l = a.size();
        for (int i = 0; i < (l/2)+1; i++)
            if (a[i] != a[l-1-i]) return false;

        return true;
    }
};