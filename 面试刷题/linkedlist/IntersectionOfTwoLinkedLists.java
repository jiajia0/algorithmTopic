package linkedlist;

/**
 * @Author majialong
 * @Date 2021/1/30 10:14
 * @Descreption 相交链表，找出两个链表的相交点
 **/
public class IntersectionOfTwoLinkedLists {
     class Solution {
        public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
            ListNode la = headA;
            ListNode lb = headB;
            // 相等于把A/B链表分别放到另一个链表的前面，这样两条链表的长度就是相等的（公共部分可以忽略）
            // a + c + b + c = b + c + a + c -> a + b + c = b + a + c
            // 然后先遍历自己的链表，便利完成之后再遍历另一条链表，因为前面部分两个链表相加后都相等
            // 所以如果存在交点，则会在相交的C入口处相等。如果不存在则两个都会为null
            // 关键思路：在遇到相交点之前，两个链表走过的长度应该是相同的
            while(la != lb) {
                la = (la == null) ? headB : la.next;
                lb = (lb == null) ? headA : lb.next;
            }
            return la;
        }
    }
}
