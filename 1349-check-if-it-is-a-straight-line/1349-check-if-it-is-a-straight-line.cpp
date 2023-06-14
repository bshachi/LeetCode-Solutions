class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& c) {
        int y = c[1][1] - c[0][1];
        int x = c[1][0] - c[0][0];

        int n = c.size();
        for (int i = 2; i < n; i++) {
            if ((c[i][0] - c[i-1][0])*y != (c[i][1] - c[i-1][1])*x) return false;
        }
        return true;
    }
};