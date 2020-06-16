/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Codec {

    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        if(root == null) {
            return "";
        }
        String data = "";
        // BFS 先序遍历
        Stack<TreeNode> stk = new Stack<TreeNode>();
        while(root != null || !stk.empty()) {
            while(root != null) {
                data += String.valueOf(root.val) + ","; 
                stk.push(root);
                root = root.left;
                if(root == null) { // 左节点为空时的null
                    data += "null,";
                }
            }
            TreeNode node = stk.pop();
            root = node.right;
            if(root == null) { // 右节点为空时的null
                data += "null,";
            }
        }
        return data;
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        if(data == "") {
            return null;
        }
        String[] tree_data = data.split(",");
        TreeNode root = new TreeNode(Integer.valueOf(tree_data[0]));
        TreeNode ans = root;
        int i = 1;
        Stack<TreeNode> stk = new Stack<TreeNode>();
        stk.push(root);
        while(root != null || !stk.empty()) {
            while(root != null) {
                TreeNode node = null;
                if(!tree_data[i].equals("null")) {
                    node = new TreeNode(Integer.valueOf(tree_data[i]));
                    stk.push(node);
                }
                i++;
                root.left = node;
                root = node;
            }
            
            TreeNode p = stk.pop(); // 栈中取出一个元素
            TreeNode node = null;
            if(!tree_data[i].equals("null")) { // 如果下一个节点不为空null，则作为p的右节点
                node = new TreeNode(Integer.valueOf(tree_data[i]));
                stk.push(node);
            }
            p.right = node;
            root = node;
            i++;
            //System.out.println(i + "," + stk.size());
            
        }
        return ans;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.deserialize(codec.serialize(root));