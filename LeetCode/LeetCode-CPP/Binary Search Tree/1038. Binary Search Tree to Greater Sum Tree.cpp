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
    int num = 0;
    void genTree(TreeNode* root) {
        if((root == NULL))
            return;
        bstToGst(root->right);
        root->val += num;
        num = root->val;
        bstToGst(root->left);
    }

    TreeNode* bstToGst(TreeNode* root) {
        genTree(root);
        return root;
    }
};
