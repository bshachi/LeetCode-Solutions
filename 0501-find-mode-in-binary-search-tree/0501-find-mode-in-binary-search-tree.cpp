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
private:
    unordered_map<int,int> mp;
public:
    void traverse(TreeNode* node) {
        mp[node->val]++;
        if (node->left) traverse(node->left);
        if (node->right) traverse(node->right);
    }
    vector<int> findMode(TreeNode* root) {
        traverse(root);
        int max = mp[root->val];
        vector<int> ans = {root->val};

        for (auto x:mp) {
            if (x.second > max) {
                max = x.second;
                ans = {x.first};
                cout<<"bvjs  "<<max<<x.first<<endl;
            }
            else if (x.second == max) {
                if (x.first == root->val) continue;
                max = x.second;
                ans.push_back(x.first);
                cout<<max<<x.first<<endl;
            }
        }
        return ans;
    }
};