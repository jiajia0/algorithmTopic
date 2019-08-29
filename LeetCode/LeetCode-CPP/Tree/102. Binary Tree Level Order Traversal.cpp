#include "BinaryTree.cpp"
#include <iostream>
#include <vector>
#include <queue>
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
// 传统的方法，使用栈
/*class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL)
            return ans;
        queue<TreeNode*> nodes;
        nodes.push(root);
        while(!nodes.empty()) {
            vector<int> levelOfNode;// 用来保存当前层的节点
            int n = nodes.size(); // 记录当前层共有多少个节点

            while(n--) {
                TreeNode* node = nodes.front();
                nodes.pop();
                levelOfNode.push_back(node->val);
                if(node->left)
                    nodes.push(node->left);
                if(node->right)
                    nodes.push(node->right);
            }

            ans.push_back(levelOfNode);
        }
        return ans;
    }
};*/

// 利用递归和树的深度进行计算
class Solution {
public:
    void calOrder(int deep, TreeNode* root, vector<vector<int>> &ans) {
        if(root == NULL)
            return;
        if(deep == ans.size()) {

            ans.push_back(vector<int>());
        }
        ans[deep].push_back(root->val);
        calOrder(deep + 1, root->left, ans);
        calOrder(deep + 1, root->right, ans);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        calOrder(0, root, ans);
        return ans;
    }
};

int main() {
    TreeNode* pNode3 = CreateTreeNode(3);
    TreeNode* pNode9 = CreateTreeNode(9);
    TreeNode* pNode20 = CreateTreeNode(20);
    ConnectTreeNodes(pNode3, pNode9, pNode20);

    TreeNode* pNode15 = CreateTreeNode(15);
    TreeNode* pNode7 = CreateTreeNode(7);
    ConnectTreeNodes(pNode20, pNode15, pNode7);

    Solution s;
    vector<vector<int>> ans = s.levelOrder(pNode3);
    for(int i = 0; i < ans.size(); i++) {
        for(int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    //PrintTree(pNode5);
    return 0;
}
