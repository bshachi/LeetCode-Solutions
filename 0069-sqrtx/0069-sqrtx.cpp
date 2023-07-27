class Solution {
public:
    int mySqrt(int x) {
        if (x == 1) return 1;
        int s = 0, e = x, m;

        while (s < e) {
            m = (s + e)/2;
            if (m > x / m) {
                if (m - 1 <= x/(m-1)) return m-1;
                e = m - 1;
            }
            else {
                if (m + 1 > x/(m+1)) return m;
                s = m + 1;
            }
        }

        return s;
    }
};