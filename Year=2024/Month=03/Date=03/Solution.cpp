// Problem Link : https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/



// Solution //
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int idx = 0;
        ListNode *node1 = head, *node2 = head;
        ListNode *prevNode = NULL;
        ListNode *newHead = head;
        while( idx<n ) node2 = node2->next, idx+=1;
        while( node2 ){
            node2 = node2->next;
            prevNode = prevNode? prevNode->next : node1;
            node1 = node1->next;
        }
        if( prevNode ){
            prevNode->next = node1->next;
        } else{
            newHead = head->next;
        }
        return newHead;
    }
};