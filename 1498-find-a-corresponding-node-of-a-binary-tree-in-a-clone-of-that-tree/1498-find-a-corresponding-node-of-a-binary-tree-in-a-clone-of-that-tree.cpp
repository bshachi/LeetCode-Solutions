/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode* node;
        if (original == target) return cloned;
        if (original->left) node = getTargetCopy(original->left, cloned->left, target);
        if (node) return node;
        if (original->right) node = getTargetCopy(original->right, cloned->right, target);
        return node;
    }
};