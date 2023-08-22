class Solution {
public:
    string convertToTitle(int c) {
        int temp;
        string ans = "";
        while (c) {
            temp = c%26;
            c /= 26;
            if (!temp) {
                temp = 26;
                c--;
            }
            ans = char(temp+64) + ans;
        }
        return ans;
    }
};