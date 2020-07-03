/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public TreeNode sortedArrayToBST(int[] nums) {
        if(nums.length == 0) {
            return null;
        }
        Stack<Integer> l_r_index = new Stack<Integer>();
        Stack<TreeNode> path = new Stack<TreeNode>();
        l_r_index.push(0);
        l_r_index.push(nums.length - 1);
        TreeNode root = new TreeNode(0);
        path.push(root);
        while(!path.isEmpty()) {
            int r_index = l_r_index.pop();
            int l_index = l_r_index.pop();
            //System.out.println(l_index + " " + r_index);
            int mid = l_index + (r_index - l_index) / 2;
            TreeNode node = path.pop(); // 取出存放的节点，将其设置为mid
            node.val = nums[mid];
            // 设置该node的左右节点
            if(l_index <= mid - 1) { // 确定mid左边还有节点
                node.left = new TreeNode(0);
                path.push(node.left);
                l_r_index.push(l_index);
                l_r_index.push(mid - 1);
            }
            if(r_index >= mid + 1) { // 确定mid右边还有节点
                node.right = new TreeNode(0);
                path.push(node.right);
                l_r_index.push(mid + 1);
                l_r_index.push(r_index);
            }
        }
        return root;
    }
}