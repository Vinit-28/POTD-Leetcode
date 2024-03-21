// Problem Link : https://leetcode.com/problems/reverse-linked-list/description/


// Solution //
class Solution {
public:
    ListNode *newHead, *originalHead;
    ListNode* reverseList(ListNode* head) {
        if( head==NULL ) return NULL;
        originalHead = head;
        rec(head);
        return newHead;
    }
    
    ListNode* rec(ListNode *node){
        if( node->next == NULL ){
            newHead = node;
            return node;
        }
        
        rec(node->next)->next = node;
        if( node==originalHead ) node->next=NULL;
        return node;
    }
};