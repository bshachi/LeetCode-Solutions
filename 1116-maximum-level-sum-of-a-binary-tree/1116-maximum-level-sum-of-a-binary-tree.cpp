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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        TreeNode* x;
        q.push(root);
        int sum = 0, n, ans = 1, lev = 0, max = root->val;
        while (!q.empty()) {
            lev++;
            sum = 0;

            n = q.size();
            for (int i = 0; i < n; i++) {
                x = q.front();
                q.pop();
                sum += x->val;
                if (x->left) q.push(x->left);
                if (x->right) q.push(x->right);
            }

            if (sum > max) {
                max = sum;
                ans = lev;
            }
        }

        return ans;
    }
};