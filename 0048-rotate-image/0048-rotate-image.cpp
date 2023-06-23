class Solution {
public:
    void swap(int& a, int& b, int& c, int& d) {
        int temp = d;
        d = c;
        c = b;
        b = a;
        a = temp;
    }
    void rotate(vector<vector<int>>& m) {
        int n = m.size();
        for (int i = 0; i <= n/2; i++) {
            for (int j = i; j < n - i - 1; j++) {
                swap(m[i][j], m[j][n - 1 - i], m[n - 1 - i][n - 1 - j], m[n - 1 - j][i]);
            }
        }
    }
};