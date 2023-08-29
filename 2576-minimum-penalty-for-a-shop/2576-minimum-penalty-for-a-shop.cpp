class Solution {
public:
    int bestClosingTime(string cus) {
        int n = cus.size(), p = 0, ans = n;
        for (char c:cus) if (c == 'N') p++;

        int mp = p;
        for (int i = n-1; i >= 0; i--) {
            if (cus[i] == 'Y') p++;
            else p--;
            if (p <= mp) {
                mp = p;
                ans = i;
            }
        }       
        return ans;
    }
};