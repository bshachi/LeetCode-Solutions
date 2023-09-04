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
    bool isValidBST(TreeNode* root, long mini = (long)INT_MIN - 1, long maxi = (long)INT_MAX + 1) {
        if (!root) return true;

        if (root->val <= mini || root->val >= maxi) return false;
        return (isValidBST(root->left, mini, root->val) && isValidBST(root->right, root->val, maxi));
    }
};