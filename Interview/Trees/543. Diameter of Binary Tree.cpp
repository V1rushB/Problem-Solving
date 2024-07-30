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
    int mx = -1e3;

    int dfs(TreeNode* root) {
        if(root == nullptr)
            return -1;

        int left = dfs(root->left);
        int right = dfs(root->right);

        mx = max(mx, left + right + 2);
        return 1 + max(left,right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int x = dfs(root);
        if(x == -1)
            return 0;
        return mx;
    }
};

