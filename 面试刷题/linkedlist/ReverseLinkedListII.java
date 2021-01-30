package linkedlist;

/**
 * @Author majialong
 * @Date 2021/1/30 12:33
 * @Descreption 反转链表II，将n到m之前的链表进行反转
 **/
public class ReverseLinkedListII {
    // 迭代方法1
    class Solution1 {
        // 类似头插法
        public ListNode reverseBetween(ListNode head, int m, int n) {
            if(head == null || head.next == null) {
                return head;
            }
            ListNode result = new ListNode(0);  // 是为了防止头节点也被反转的情况
            result.next = head;
            ListNode pre = result;
            // 将pre移动到将要发生反转的前一个位置,并且后面操作中固定不变
            while(m != 1) {
                m--;
                n--;
                pre = pre.next;
            }
            ListNode cur = pre.next;    // cur不需要主动更新，会随着操作逐渐向后
            ListNode next = cur.next;   // 需要主动更新为cur的下一个节点
            // 每次将next与前后节点断开，cur和next的下一个节点相连接
            // 然后和链表的头插法类似，把next节点插入到pre的后面
            // 插入完成之后，此时cur的位置会比原来的位置向后移动一位
            for(int i = 0; i < n - m; i++) {
                cur.next = next.next;   // cur和next的后一位直接相连接，相当于把next分割出来
                next.next = pre.next;
                pre.next = next;        // 使用头插法将next连接到pre后面
                next = cur.next;        // 更新下一个next节点
            }
            return result.next;
        }
    }

    // 迭代方法2
    class Solution2 {
        // 类似整体反转的方法
        public ListNode reverseBetween(ListNode head, int m, int n) {
            if(head == null || head.next == null) {
                return head;
            }
            ListNode cur, next, pre, start, end;
            ListNode result = new ListNode(0);
            result.next = head; // 防止head节点也发生变化
            start = result;     // start移动到反转节点的前面，后面不发生变化
            while(m != 1) {
                start = start.next;
                m--;
                n--;
            }
            pre = null;
            cur = start.next;
            end = cur;  // end指向反转后的尾节点，也就是反转前的头节点，也不会发生变化
            for(int i = 0; i <= n - m; i++) {   // 每次让cur指向pre，然后向后移动一位
                next = cur.next;
                cur.next = pre;
                pre = cur;
                cur = next;
            }
            end.next = cur;     // end为刚开始反转区间的头节点，现在反转后为尾节点，尾节点与后面的链表相连接
            start.next = pre;   //  反转区间前面的部分与反转后的头节点相连接
            return result.next;
        }
    }


    // 递归的方法
    class Solution3 {

        ListNode start = null;    // n个节点反转之后的新起点位置
        // 递归反转前N个节点，非递归反转前N个方法和上面mn代码类似，只是把m固定为1即可
        public ListNode reverseN(ListNode head, int n) {
            if(n == 1) {
                start = head.next;
                return head;
            }
            ListNode last = reverseN(head.next, n - 1);
            head.next.next = head;
            head.next = start;
            return last;
        }

        // 递归反转m，n之间的节点，以反转前N个节点为基础
        // 将head逐渐向后移动到需要范围的位置上，然后把当前位置当作头节点，执行反转前n个节点的代码即可
        public ListNode reverseBetween(ListNode head, int m, int n) {
            if(m == 1) {
                return reverseN(head, n);
            }
            // head.next只有在m-1为1时才会进行修改，其他情况下head与后面的链接关系不会发生变化
            head.next = reverseBetween(head.next, m - 1, n - 1);
            return head;
        }
    }
}
