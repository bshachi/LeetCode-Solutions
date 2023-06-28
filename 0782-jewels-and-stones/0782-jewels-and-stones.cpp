class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int ans = 0;
        for (char j:jewels) {
            for (char s:stones) {
                if (j == s) ans++;
            }
        }
        return ans;
    }
};