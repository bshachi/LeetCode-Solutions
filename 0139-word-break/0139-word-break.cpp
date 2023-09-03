class Solution {

private:
    struct node{
        node* chars[26];
        bool flag = false;
    };
    node* root;
    vector<int> memo;

public:
    bool canBeSegmented(string& s, int index) {
        int n = s.size(), i = index; 
        if (i == n) return true;
        if (memo[index] != -1) return memo[index];
        
        node* ptr = root;
        for (;i < n; i++) {
            char c = s[i];
            
            if (!ptr->chars[c-'a']) {
                memo[index] = 0;
                return false;
            }
            ptr = ptr->chars[c-'a'];
            if (ptr->flag) {
                if (canBeSegmented(s, i+1)) {
                    memo[index] = 1;
                    return true;
                }
            }
        }

        memo[index] = 0;
        return false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        memo.resize(s.size(), -1);

        root = new node();
        for (string& word:wordDict) {
            node* ptr = root;
            for (char c:word) {
                if (!ptr->chars[c-'a']) ptr->chars[c-'a'] = new node();
                ptr = ptr->chars[c-'a'];
            }
            ptr->flag = true;
        }

        return canBeSegmented(s, 0);
    }
};