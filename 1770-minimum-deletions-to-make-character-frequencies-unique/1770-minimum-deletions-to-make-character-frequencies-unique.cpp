class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq (26, 0);
        for (char c:s) freq[c-'a']++;

        sort(freq.begin(), freq.end(), greater<int>());
        // for (int x:freq)cout<<x<<" ";
        int ans = 0;
        for (int i = 0; i < 26 && freq[i]>0; i++) {
            for (int j = i+1; j < 26 && freq[j] == freq[i]; j++) {
                ans++;
                freq[j]--;
            }
        }
        // cout<<endl; for (int x:freq)cout<<x<<" ";
        return ans;
    }
};