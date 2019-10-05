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
    int pathSum(TreeNode* root, int sum) {
        if(root == NULL)
            return 0;
        // 从当前节点开始查找path为sum的路径值，加上当前节点的左右节点的
        return pathSumFrom(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
    
    int pathSumFrom(TreeNode* node, int sum) {
        if(node == NULL)
            return 0;
        // 判断当前节点是否能够满足，并且加上左右子树满足的数量
        return (node->val == sum ? 1 : 0) + pathSumFrom(node->left, sum - node->val) + pathSumFrom(node->right, sum - node->val);
    }
    
};