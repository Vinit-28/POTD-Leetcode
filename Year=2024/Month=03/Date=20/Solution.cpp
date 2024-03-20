// Problem Link : https://leetcode.com/problems/merge-in-between-linked-lists/description/


// Solution //
class Solution {
    public ListNode mergeInBetween(ListNode list1, int a, int b, ListNode list2) {
        ListNode start = null, end = null;
        ListNode node = list1, list2End = list2;
        int idx = 0;
        while( node != null ){
            if( idx == a-1 ){
                start = node;
            } else if( idx == b+1 ){
                end = node;
            }
            node = node.next;
            idx += 1;
        }
        while( list2End.next != null ){
            list2End = list2End.next;
        }
        start.next = list2;
        list2End.next = end;
        return list1;
    }
}