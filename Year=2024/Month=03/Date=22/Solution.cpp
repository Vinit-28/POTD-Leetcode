// Problem Link : https://leetcode.com/problems/palindrome-linked-list/description/


// Solution //
class Solution {
public:
    int n, half;
    ListNode *lastNode, *secondHalf;

    ListNode* reverseHalf(ListNode *node, int idx){
        if( !node ){
            n = idx;
            half = (n&1)? n/2 : n/2-1;
            lastNode = NULL;
        } else{
            ListNode *revHead = reverseHalf(node->next, idx+1);
            if( idx > half ){
                lastNode? lastNode->next = node : NULL;
                lastNode = node;
                lastNode->next = NULL;
                return revHead? revHead : node;
            } else if( idx == half ){
                secondHalf = revHead;
            }
        }
        return NULL;
    }

    bool isPalindrome(ListNode* head) {
        if( head->next == NULL ) return true;
        else if( head->next->next == NULL ) return head->val == head->next->val;
        reverseHalf(head, 0);
        ListNode *node1 = head, *node2 = secondHalf;
        while( node2 ){
            if( node1->val != node2->val ) return false;
            node1 = node1->next;
            node2 = node2->next;
        }
        return true;
    }
};