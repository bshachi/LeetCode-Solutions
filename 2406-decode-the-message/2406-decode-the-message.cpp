class Solution {
public:
    string decodeMessage(string key, string message) {
        string ans = "";
        int mapping[26];
        for (int i = 0; i<26; i++) mapping[i] = -1;

        int k = 0;
        for (char x:key)
        {
            if (x == ' ' || mapping[int(x)-97] != -1) continue;
            mapping[int(x)-97] = k;
            k++;
        }

        for (char x:message)
        {
            if (x == ' ') 
            {
                ans.push_back(' ');
                continue;
            }
            ans.push_back(char(mapping[int(x)-97] + 97));
        }

        return ans;

    }
};