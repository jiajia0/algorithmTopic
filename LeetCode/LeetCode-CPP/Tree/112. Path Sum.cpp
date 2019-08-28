#include "BinaryTree.cpp"
#include <iostream>
using namespace std;
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
    bool calPathSum(TreeNode* root, int sum, int now) {
        if(root == NULL)
            return false;
        // 若此时为叶子结点
        if(root->left == NULL && root->right == NULL) {
            return sum == now+root->val;
        } else {
            return (calPathSum(root->left, sum, now + root->val) || calPathSum(root->right, sum, now + root->val));
        }
    }

    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL)
            return false;
        return calPathSum(root, sum, 0);
    }
};

int main() {
    TreeNode* pNode5 = CreateTreeNode(5);
    TreeNode* pNode41 = CreateTreeNode(4);
    TreeNode* pNode8 = CreateTreeNode(8);
    ConnectTreeNodes(pNode5, pNode41, pNode8);

    TreeNode* pNode11 = CreateTreeNode(11);
    TreeNode* pNode13 = CreateTreeNode(13);
    TreeNode* pNode42 = CreateTreeNode(4);
    ConnectTreeNodes(pNode41, pNode11, NULL);
    ConnectTreeNodes(pNode8, pNode13, pNode42);

    TreeNode* pNode7 = CreateTreeNode(7);
    TreeNode* pNode2 = CreateTreeNode(2);
    TreeNode* pNode1 = CreateTreeNode(1);
    ConnectTreeNodes(pNode11, pNode7, pNode2);
    ConnectTreeNodes(pNode42, NULL, pNode1);

    Solution s;
    bool ans = s.hasPathSum(pNode5, 22);
    cout << ans;

    //PrintTree(pNode5);
    return 0;
}
