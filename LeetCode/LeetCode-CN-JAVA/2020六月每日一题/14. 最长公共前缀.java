// class Solution {
//     public String longestCommonPrefix(String[] strs) {
//         if(strs.length == 0) {
//             return "";
//         }
//         String ans = "";
//         for(int i = 0; i < strs[0].length(); i++) {
//             char ch = strs[0].charAt(i); // 每次取一个字母作为前缀，然后与其他字符串进行对于看看是否一致
//             for(int j = 1 ; j < strs.length; j++) {
//                 if(i >= strs[j].length() || ch != strs[j].charAt(i)) {
//                     return ans;
//                 }
//             }
//             ans += ch;
//         }
//         return ans;
//     }
// }


class Solution {

    // 使用Trie树
    class TrieNode {
        public char data;
        public TrieNode[] children = new TrieNode[26];
        public boolean isEndingChar = false;
        public TrieNode(char data) {
            this.data = data;
        }
    }

    private TrieNode root = new TrieNode('/'); // 构建一个根节点
    private String ans = "";
    // 想trie树中插入一个节点
    public void insert(String str) {
        TrieNode p = root;
        String temp_ans = "";
        for(int i = 0; i < str.length(); i++) {
            int index = str.charAt(i) - 'a'; // 计算当前字符的索引
            if(p.children[index] != null) { // 不等于null说明存在前缀
                temp_ans += str.charAt(i);
            }
            if(p.children[index] == null) {
                TrieNode newNode = new TrieNode(str.charAt(i));
                p.children[index] = newNode;
            }
            p = p.children[index];
        }
        //System.out.println("ans:" + ans + ", temp_ans:" + temp_ans);
        if(str != ans) { // 如果当前字符和答案一样，不必更新答案
            ans = temp_ans.length() < ans.length() ? temp_ans : ans;
        }
        
        p.isEndingChar = true;
    }
    public String longestCommonPrefix(String[] strs) {
        if(strs.length == 0) {
            return "";
        }
        ans = strs[0];
        for(int i = 0 ; i < strs.length; i++) {
            insert(strs[i]); // 插入的同时会计算前缀
        }
        return ans;
    }
}