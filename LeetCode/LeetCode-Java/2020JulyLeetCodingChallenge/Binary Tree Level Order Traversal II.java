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

class Solution {
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        List<List<Integer>> ans = new ArrayList<List<Integer>>();
        getOrderTraversal(0, ans , root);
        Collections.reverse(ans);
        return ans;
    }
    
    public void getOrderTraversal(int level, List<List<Integer>> ans, TreeNode node) {
        if(node == null) {
            return;
        }
        // 说明当前层正好是下一个需要访问的层数，比如size=1，level为1，则size为1说明已经访问了第0层，接下来该访问第1层了
        if(ans.size() == level) { 
            ans.add(new ArrayList<Integer>());
        }
        ans.get(level).add(node.val); // 给对应的层里面加入数据
        getOrderTraversal(level + 1, ans, node.left);
        getOrderTraversal(level + 1, ans, node.right);
    }
    
}

// class Solution {
//     public List<List<Integer>> levelOrderBottom(TreeNode root) {
//         List<List<Integer>> ans = new ArrayList<List<Integer>>();
//         if(root == null) {
//             return ans;
//         }
//         Queue<TreeNode> path = new LinkedList<TreeNode>();
//         path.offer(root);
//         while(path.size() != 0) {
//             ArrayList<Integer> sub_ans = new ArrayList<Integer>();
//             int n = path.size();
//             for(int i = 0; i < n; i++) {
//                 TreeNode node = path.poll();
//                 sub_ans.add(node.val);
//                 if(node.left != null) {
//                     path.offer(node.left);
//                 }
//                 if(node.right != null) {
//                     path.offer(node.right);
//                 }
//             }
//             ans.add(sub_ans);
//         }
//         Collections.reverse(ans);
//         return ans;
//     }
// }