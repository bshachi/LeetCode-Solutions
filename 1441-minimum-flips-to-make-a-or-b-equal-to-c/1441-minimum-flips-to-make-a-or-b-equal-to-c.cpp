class Solution {
public:
    int minFlips(int a, int b, int c) {
        int count = 0;
        bool x, y;
        while (a || b || c) {
            cout<<a<<" "<<b<<" "<<c<<endl;
            x = a & 1;
            y = b & 1;
            if (c & 1) {
                if (!(x || y)) count++;
            }
            else {
                if (x ^ y) count++;
                else if (x & y) count += 2;
            }

            a = a >> 1;
            b = b >> 1;
            c = c >> 1;
        }

        return count;
    }
};