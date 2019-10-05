/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
class Solution {
public:
    
    TreeNode* dfs(int left, int right, vector<int>& nums) {
        if(left == right) {
            return new TreeNode(nums[left]);
        }
        int curr = ceil((left + right) / 2.0); // 计算出当前节点所处的位置,向上取整
        //cout << left << " " << curr <<  " " << right << endl;
        TreeNode* node = new TreeNode(nums[curr]);
        if(curr == right) { //只剩下两个节点
            node->left = new TreeNode(nums[left]);
            node->right = NULL;
        } else {
            node->left = dfs(left, curr - 1, nums);
            node->right = dfs(curr + 1, right, nums);
        }
        return node;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0)
            return NULL;
        return dfs(0, nums.size() - 1, nums);;
    }
};
*/

class Solution {
public:
    
    TreeNode* dfs(int left, int right, vector<int>& nums) {
        if(left > right) {
            return NULL;
        }
        int curr = (left + right) / 2; // 计算出当前节点所处的位置,向上取整
        //cout << left << " " << curr <<  " " << right << endl;
        TreeNode* node = new TreeNode(nums[curr]);
        node->left = dfs(left, curr - 1, nums);
        node->right = dfs(curr + 1, right, nums);
        
        return node;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0)
            return NULL;
        return dfs(0, nums.size() - 1, nums);;
    }
};