/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    unordered_map<int,int> mp;
    int maxi = 1;

public:
    int st_sum(TreeNode* node) {
        if (!node) return 0;
        node->val += st_sum(node->left) + st_sum(node->right);
        maxi = max(++mp[node->val], maxi);
        return node->val;
    }

    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> ans;
        st_sum(root);
        for (auto x:mp) {
            if (x.second == maxi) ans.push_back(x.first);
        }
        return ans;
    }
};