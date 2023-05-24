class Solution {
public:


    string PalEven(string& s, int i) {
        int j = 0, n = s.size();
        string str1 ="";

        while (i - j >=0 && i + j + 1 < n) {
            if (s[i - j] == s[i + j + 1]) str1 = s[i - j] + str1 + s[i - j];
            else break;
            j++;
        }

        return str1;
    }
    

    string PalOdd(string& s, int i) {
        int j = 1, n = s.size();
        string str1 ="";
        str1.push_back(s[i]);

        while (i - j >=0 && i + j < n) {
            if (s[i - j] == s[i + j]) str1 = s[i - j] + str1 + s[i - j];
            else break;
            j++;
        }

        return str1;
    }
    

    string longestPalindrome(string s) {
        string temp, temp1, temp2, ans = "";

        int n = s.size();
        int mid = n/2;
        if (n%2 == 0) mid--;

        ans.push_back(s[mid]);
        int end = n;

        for (int i = mid; i<end; i++) {
            temp1 = PalEven(s, i);
            temp2 = PalEven(s, 2*mid - i);
            temp = temp1.size() > temp2.size() ? temp1 : temp2;

            if (temp.size() > ans.size()) {
                ans = temp;
                end = n - ans.size()/2 -1;
            }
        }

        end = min(n - 1, end + 1);

        for (int i = mid; i<end; i++) {
            temp1 = PalOdd(s, i);
            temp2 = PalOdd(s, 2*mid - i);
            temp = temp1.size() > temp2.size() ? temp1 : temp2;

            if (temp.size() > ans.size()) {
                ans = temp;
                end = n - ans.size()/2 -1;
            }
        }

        return ans;

    }
};