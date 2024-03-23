// Problem Link : https://leetcode.com/problems/reorder-list/description/


// Solution //
class Solution {
    int listLen, listHalf;
    ListNode revHead;
    public void reorderList(ListNode head) {
        listLen = 0;
        listHalf = 0;
        revHead = null;
        // Reversing the second half of the list //
        reverseSecondHalf(head, 1);
        // Reordering the list //
        ListNode left = head, right = revHead;
        ListNode prevNode = null;
        while( left != revHead ){
            ListNode leftNext = left.next;
            ListNode rightNext = right.next;
            if( prevNode != null ){
                prevNode.next = left;
            }
            left.next = right;
            prevNode = right;
            left = leftNext;
            right = rightNext;
        } 
    }

    public ListNode reverseSecondHalf(ListNode node, int nodeIdx){
        if( node.next == null ){
            revHead = node;
            listLen = nodeIdx;
            listHalf = (listLen/2)+1;
            return node;
        } else{
            ListNode rll = reverseSecondHalf(node.next, nodeIdx+1);
            if( nodeIdx >= listHalf ){
                rll.next = node;
                node.next = null;
            } else if( nodeIdx == (listHalf-1) ){
                node.next = revHead;
            }
            return node;
        }
    }
}