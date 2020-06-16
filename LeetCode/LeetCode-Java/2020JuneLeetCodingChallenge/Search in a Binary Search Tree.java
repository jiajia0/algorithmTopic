/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
// class Solution {
//     public TreeNode searchBST(TreeNode root, int val) {
//         if(root == null) {
//             return null;
//         }
//         if(val < root.val) {
//             return searchBST(root.left, val);
//         } else if(val > root.val) {
//             return searchBST(root.right, val);
//         }
//         return root;
//     }
// }

class Solution {
    public TreeNode searchBST(TreeNode root, int val) {
        if(root == null) {
            return null;
        }
        TreeNode ans = root;
        
        while(ans != null) { // 数据不为空
            if(ans.val > val) {
                ans = ans.left;
            } else if(ans.val < val) {
                ans = ans.right;
            } else {
                return ans;
            }
        }
        return ans;
    }
}