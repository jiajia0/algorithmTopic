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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == q || root == p) {
            return root;
        }

        TreeNode* leftNode = lowestCommonAncestor(root->left,p,q); // 去左边查找
        TreeNode* rightNode = lowestCommonAncestor(root->right, p, q); // 去右边查找

        if(leftNode == NULL) { // 说明此时左边没有找到节点 ， 返回右边的查找结果
            return rightNode;
        }
        if(rightNode == NULL) {
            return leftNode;
        }
        return root;
    }
};