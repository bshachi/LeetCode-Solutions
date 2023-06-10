class Solution {
public:
    int maxValue(int n, int i, int maxSum) {
        maxSum -= n;
        if (i >= n/2) i = n - i - 1;

        int k = sqrt(maxSum);
        if (k <= i + 1) return ++k;

        int rdiff = 0, ldiff = ((k-i)*(k-i-1))/2; 
        if (k + i > n) rdiff = ((k + i - n)*( k + i - n + 1))/2;

        while (k + i < n) {
            k++;
            ldiff += k - i - 1;
            if (k > sqrt(maxSum + ldiff)) return k;
        }

        maxSum -= k*k - ldiff - rdiff;
        return k + maxSum/n + 1;
    }
};
