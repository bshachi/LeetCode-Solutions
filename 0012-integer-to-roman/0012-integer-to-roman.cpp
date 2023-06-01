class Solution {
public:
    string intToRoman(int num) {
        string ans = "";

        string th[] = {"", "M", "MM", "MMM"};
        string h[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string t[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        string o[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

        ans += th[num/1000];
        num %= 1000;

        ans += h[num/100];
        num %= 100;

        ans += t[num/10];
        num %= 10;

        ans += o[num];
        return ans;
    }
};