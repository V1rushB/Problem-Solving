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

    pair<bool,int> dfs(TreeNode *root) {
        if(root == nullptr)
            return make_pair(true,-1);

        pair<bool,int> left = dfs(root->left);
        pair<bool,int> right = dfs(root->right);

        int balanced = abs(left.second - right.second) <=1 && left.first && right.first;
        return make_pair(balanced,1+max(left.second,right.second));

    }

    bool isBalanced(TreeNode* root) {
        return dfs(root).first;
    }
};

