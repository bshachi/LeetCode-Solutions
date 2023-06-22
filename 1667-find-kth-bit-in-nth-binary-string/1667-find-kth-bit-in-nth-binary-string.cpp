class Solution {
public:
    char findKthBit(int n, int k) {
        int x, p = 24, q = -1;
        bool flip = 0, base = 0, val = 0;

        while (!val) {
            q++;
            val = k & (1 << q);
        }
        if (q) base = 1;
        
        while (p > q) {
            val = 0;
            while (!val) {
                p--;
                val = k & (1 << p);
            }

            if(p == q) return char(48 + (flip ^ base));
            x = 1 << (p + 1);
            flip = !flip;
            k = x - k;
        }
        return '0';
    }
};