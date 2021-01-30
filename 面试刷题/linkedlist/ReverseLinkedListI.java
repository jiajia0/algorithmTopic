package linkedlist;

/**
 * @Author majialong
 * @Date 2021/1/30 10:33
 * @Descreption 反转整个链表
 **/
public class ReverseLinkedListI {
    // 迭代方法
    class Solution1 {
        public ListNode reverseList(ListNode head) {
            if(head == null || head.next == null) {
                return head;
            }
            // 使用前中后三个关键节点，每次让cur节点反转指向前面pre节点
            // 然后更新前中后三个节点，直到cur达到最后一个位置，然后cur被赋值为null
            // 此时返回pre节点，也就是最后一个非null节点
            ListNode pre = null;
            ListNode cur = head;
            while(cur != null) {
                ListNode next = cur.next;   // 不做赋值操作，只是为了记录cur的下一个位置
                cur.next = pre;
                pre = cur;
                cur = next;
            }
            return pre;
        }
    }

    // 递归方法
    class Solution2 {
        // 将链表进行反转，并且返回反转后的头节点
        public ListNode reverseList(ListNode head) {
            if(head == null || head.next == null) {
                return head;
            }
            // 先对后面的链表进行反转，然后让当前链表的下一个节点反转指向当前节点
            // 必须先处理后面链表，然后处理当前链表，如果反过来，则会发生链表断开的情况导致无法处理后面链表
            ListNode last = reverseList(head.next);
            head.next.next = head;
            head.next = null;   // 反转完成之后，此时head就是尾节点，需要将尾节点next指向null
            return last;
        }
    }


}
