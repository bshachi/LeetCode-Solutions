class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        while (x/10) {
            ans *= 10;
            ans += x%10;

            x /= 10;
        }

        
        if (ans > INT_MAX/10 || ans < INT_MIN/10) return 0;
        if ((ans == INT_MAX/10 && x > INT_MAX%10) || (ans == INT_MIN/10 && x < INT_MIN%10)) return 0;

        
        ans *= 10;
        ans += x%10;

        return ans;
    }
};