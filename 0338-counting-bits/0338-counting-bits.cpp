class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        ans.push_back(0);
        
        for (int s = 1; s <= n; s = ans.size()) 
            for (int i = 0; i < s && i + s <= n; i++) 
                ans.push_back(ans[i]+1);
            
        return ans;
    }
};