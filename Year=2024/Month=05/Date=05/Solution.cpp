// Problem Link : https://leetcode.com/problems/delete-node-in-a-linked-list/description/


// Solution //
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode *prev;
        while( node->next ){
            node->val = node->next->val;
            prev = node;
            node = node->next;
        }
        prev->next = NULL;
    }
};