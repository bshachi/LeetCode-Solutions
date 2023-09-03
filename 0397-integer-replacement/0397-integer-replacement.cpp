class Solution {
public:
    int integerReplacement(int n) {
        int ans = 0;
        
        while(n != 1 && n != 3) {
            ans++;
            if ((n & 1) && ((n >> 1) & 1)) {
                while (n & 1) {
                    ans++;
                    n = n >> 1;
                }
                n++;
            }
            else if (n & 1) {
                ans++;
                n = n >> 1;
            }
            else n = n >> 1;
        }

        if (n == 3) ans += 2;
        return ans;
    }
};