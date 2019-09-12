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
    
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if(root == NULL)
            return root;
        // 这两句可以定位到 L <= root->val <= R 中。
        if(root->val > R)
            return trimBST(root->left, L, R); // 这里直接返回合适的节点，与上一个节点进行拼接
        if(root->val < L)
            return trimBST(root->right, L, R);
        // 这两句进行构建二叉搜索树
        root->left = trimBST(root->left, L, R);
        root->right = trimBST(root->right, L, R);
        return root;
    }
};