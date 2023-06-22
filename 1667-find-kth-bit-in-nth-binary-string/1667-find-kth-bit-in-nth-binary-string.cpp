class Solution {
public:
    char findKthBit(int n, int k) {
        int lowest_greater_pow, current_power = 24, highest_pow_factor = -1;
        bool flip = 0, base_bit = 0, bit = 0;

        while (!bit) {
            highest_pow_factor++;
            bit = k & (1 << highest_pow_factor);
        }
        if (highest_pow_factor) base_bit = 1;
        
        while (current_power > highest_pow_factor) {
            bit = 0;
            while (!bit) {
                current_power--;
                bit = k & (1 << current_power);
            }

            lowest_greater_pow = 1 << (current_power + 1);
            flip = !flip;
            k = lowest_greater_pow - k;
        }
        
        flip = !flip;
        return char(48 + (flip ^ base_bit));
    }
};