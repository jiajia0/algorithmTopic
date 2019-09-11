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

    void dfs(TreeNode* node, vector<int>& nums) {
        if(node == NULL)
            return;
        // 中序、后序、前序都可以
        dfs(node->left, nums);
        dfs(node->right, nums);
        if(node->left == NULL && node->right == NULL)
            nums.push_back(node->val);

    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> nums1;
        vector<int> nums2;
        dfs(root1, nums1);
        dfs(root2, nums2);
        if(nums1.size() != nums2.size())
            return false;
        for(int i = 0;i<nums1.size();i++) {
            if(nums1[i] != nums2[i])
                return false;
        }
        return true;
    }
};
