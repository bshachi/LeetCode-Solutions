class Solution {
private:
    struct node{
        node* chars[26];
        bool flag = false;
    };
    node* root;

public:
    int minExtraChar(string s, vector<string>& dictionary) {
        root = new node();
        int n = s.size();
        vector<int> memo (n+1, -1);
        memo[n] = 0;

        for (string str1:dictionary) {
            node* ptr = root;
            for (char c:str1) {
                if (!ptr->chars[c-'a']) {
                    ptr->chars[c-'a'] = new node();
                }
                ptr = ptr->chars[c-'a'];
            }
            ptr->flag = true;
        }

        for (int i = n - 1; i >= 0; i--) {
            memo[i] = memo[i+1] + 1;
            node* ptr = root;

            for (int j = i; j < n; j++) {
                if (!ptr->chars[s[j] - 'a']) break;
                ptr = ptr->chars[s[j] - 'a'];
                if (ptr->flag) memo[i] = min(memo[i], memo[j+1]);
            }
        }

        return memo[0];
    }
};