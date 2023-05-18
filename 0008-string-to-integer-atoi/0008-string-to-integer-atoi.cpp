class Solution {
public:
    int myAtoi(string s) {
        int ans = 0;
        int i, current, n = s.size();
        bool neg = false;

        for (i = 0; i<n; i++) if (s[i] == ' ') continue; else break;

        if (i == n) return 0;

        if (s[i] == '+') i++;
        else if (s[i] == '-') 
        {
            neg = true;
            i++;
        }

        while (i<n)
        {
            current = int(s[i]) - 48;
            i++;


            if (current <= 9 && current >= 0)
            {
                if (ans > INT_MAX/10 || (ans == INT_MAX/10 && current > INT_MAX%10))
                {
                    if (neg) return INT_MIN;
                    return INT_MAX;
                }
                ans *= 10;
                ans += current;
            }
            else break;
        }

        if (neg) ans *= -1;
        return ans;
    }
};