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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* node;
            int f_x = 0;
            int f_y = 0;
            int size = q.size();
            while(size--) {
                node = q.front();
                q.pop();
                if(node->left != NULL && node->right != NULL) {
                    if((node->left->val == x && node->right->val == y) || (node->left->val == y && node->right->val == x))
                        return false;
                }
                if(node->val == x)
                    f_x = 1;
                if(node->val == y)
                    f_y = 1;
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            if(f_x == f_y && f_x != 0)
                return true;
        }
        return false;
    }
};