class Solution {
public:
    int minPartitions(string n) {
        int ans = 0;
        for (char c:n) {
            if (int(c) - 48 > ans) ans = int(c) - 48;
        }
        return ans;
    }
};