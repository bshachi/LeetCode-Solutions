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
    TreeNode* flattenSubtree(TreeNode* root) {
        if (root->left == NULL && root->right == NULL) return root;

        TreeNode* lend;
        if (root->left != NULL) lend = flattenSubtree(root->left);
        
        TreeNode* rend;
        if (root->right != NULL) rend = flattenSubtree(root->right);
        else {
            root->right = root->left;
            root->left = NULL;
            return lend;
        }

        if (root->left != NULL) {
            lend->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }

        return rend;
    }

    void flatten(TreeNode* root) {
        if (root == NULL) return;
        flattenSubtree(root);
    }
};