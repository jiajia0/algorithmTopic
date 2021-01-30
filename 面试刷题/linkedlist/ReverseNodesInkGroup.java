package linkedlist;

/**
 * @Author majialong
 * @Date 2021/1/30 21:33
 * @Descreption 以k个节点为单位进行反转
 **/
public class ReverseNodesInkGroup {
    // 递归方法
    class Solution1 {
        // 反转(a,b]区间内的节点，并返回反转后的头节点
        public ListNode reverse(ListNode a, ListNode b) {
            ListNode pre = null;
            ListNode cur = a;
            ListNode next;
            while(cur != b) {
                next = cur.next;
                cur.next = pre;
                pre = cur;
                cur = next;
            }
            return pre;
        }

        // 反转k个节点，然后返回反转后的头节点
        public ListNode reverseKGroup(ListNode head, int k) {
            if(head == null || k == 1) {
                return head;
            }
            ListNode a,b;
            a = b = head;   // 把a和b移动到将要反转的地方，ab中间相隔k个节点
            for(int i = 0; i < k; i++) {
                if(b == null) { // 不足k个，不进行反转
                    return head;
                }
                b = b.next;
            }
            ListNode newHead = reverse(a, b);   // 将k个进行反转，反转后a成了尾节点
            a.next = reverseKGroup(b, k);       // 继续反转后面的k个节点，然后将返回的头节点与当前的尾节点链接起来
            return newHead;
        }
    }

    // 迭代方法
    class Solution2 {
        public ListNode reverseKGroup(ListNode head, int k) {
            if(head == null || k == 1) {
                return head;
            }
            ListNode newHead, lastEnd, nextStart, cur, pre, next;
            newHead = new ListNode(0);
            newHead.next = head;
            lastEnd = newHead;
            nextStart = head;
            cur = head;
            pre = null;
            int num = 0;
            int i = 0;
            while(head != null) {   // 计算总共能够完整的反转多少次k个节点
                head = head.next;
                i++;
                if(i%k == 0) {
                    num++;
                }
            }
            while(num > 0) {
                // 进行k个节点的反转
                for(int j = 0; j < k; j++) {
                    next = cur.next;
                    cur.next = pre;
                    pre = cur;
                    cur = next;
                }
                // 记录下关键点信息
                lastEnd.next = pre;     // lastEnd指的是反转前一组k反转之后的尾节点，与当前一组k反转之后的头节点相连接
                lastEnd = nextStart;    // nextStart为当前一组k反转之前的头节点，反转之后是尾节点
                nextStart = cur;        // 记录下一组k头节点
                lastEnd.next = nextStart;   // 当前反转之后的尾节点和下一组头节点相连
                num--;
            }
            return newHead.next;
        }
    }
}
