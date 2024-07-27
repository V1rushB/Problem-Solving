//BFS
/**
 *
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
    int maxDepth(TreeNode* root) {
        int level = 0;
        if(root == nullptr) 
        return level;


        queue<TreeNode*> q(deque<TreeNode*>({root}));

        while(!q.empty()) {
            level++;
            int size = q.size();
            for(int o = 0 ; o < size;o++) {
                TreeNode* node = q.front();
                q.pop();
                if(node->left != nullptr)
                    q.push(node->left);
                if(node->right!=nullptr)
                    q.push(node->right);
            }
        }
        return level;
    }
};

