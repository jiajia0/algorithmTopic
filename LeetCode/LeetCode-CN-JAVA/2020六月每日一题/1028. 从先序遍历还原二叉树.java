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
    public TreeNode recoverFromPreorder(String S) {
        Stack<TreeNode> path = new Stack<TreeNode>();
        int pos = 0;
        while(pos < S.length()) {
            int level = 0;
            while(S.charAt(pos) == '-') { // 计算出下个层数
                level++;
                pos++;
            }
            int value = 0; // 计算出下个数字
            while(pos < S.length() && Character.isDigit(S.charAt(pos))) {
                value = value*10 + Integer.valueOf(S.charAt(pos) - '0');
                pos++;
            }
            // System.out.println(value);
            TreeNode node = new TreeNode(value);
            // level == size() 的时候说明，level正好是size()的下一层，因为size()表示已经存在了多少层，由于是从0层开始，所以加入size=2，说明已经存在了0层和1层，此时level=2说明下个节点正好应该在下一层。
            if(level == path.size()) { // 直接相等时说明当前节点应该插入到上个节点的左边
                if(!path.empty()) { // 只有相等的情况下，可能会出现level = 0 , size = 0 的初始情况，其余情况下栈不会为空
                    path.peek().left = node;
                }
            } else {
                while(level != path.size()) { // 不等时说明当前节点应该是之前路径上某个节点的右节点，所以需要回溯到之前的层次
                    path.pop();
                }
                path.peek().right = node;
            }
            path.push(node);
        }
        while(path.size() > 1) {
            path.pop();
        }
        return path.peek();
    }
}