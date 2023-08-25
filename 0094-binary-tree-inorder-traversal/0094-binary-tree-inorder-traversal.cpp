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
public:
    void inorder(TreeNode* node, vector<int>& v) {
        if (node->left) inorder(node->left, v);
        v.push_back(node->val);
        if (node->right) inorder(node->right, v);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (root) inorder(root, ans);
        return ans;
    }
};