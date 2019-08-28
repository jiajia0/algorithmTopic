#include "BinaryTree.cpp"
#include <iostream>
#include <vector>
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
    // 这里的path不能使用引用，每次递归都会分配新的内存
    /*void calPathSum(TreeNode* root,int sum, int now, vector<vector<int>>& ans,vector<int> path) {
        if(root == NULL)
            return;
        if(root->left==NULL && root->right==NULL) {
            if(sum == now + root->val) {
                //cout << "sucess " << path.size();
                path.push_back(root->val);
                ans.push_back(path);
            }
        } else {
            path.push_back(root->val);
            calPathSum(root->left, sum, now+root->val, ans, path);
            calPathSum(root->right, sum, now+root->val, ans, path);
        }
    }*/
    // 这里的path使用引用，需要在计算完叶子节点之后使用pop删除最后一个节点
    void calPathSum(TreeNode* root,int sum, int now, vector<vector<int>>& ans,vector<int>& path) {
        if(root == NULL)
            return;
        path.push_back(root->val);
        if(root->left==NULL && root->right==NULL) {
            if(sum == now + root->val)
                ans.push_back(path);
        } else {
            calPathSum(root->left,sum,now+root->val,ans,path);
            calPathSum(root->right,sum,now+root->val,ans,path);
        }
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans;
        vector<int> path;
        calPathSum(root, sum, 0, ans, path);
        return ans;
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
    TreeNode* pNode51 = CreateTreeNode(5);
    TreeNode* pNode1 = CreateTreeNode(1);
    ConnectTreeNodes(pNode11, pNode7, pNode2);
    ConnectTreeNodes(pNode42, pNode51, pNode1);

    Solution s;
    vector<vector<int>> ans = s.pathSum(pNode5, 22);
    for(int i = 0; i < ans.size(); i++) {
        for(int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    //PrintTree(pNode5);
    return 0;
}
