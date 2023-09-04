// Problem Link : https://leetcode.com/problems/linked-list-cycle/


// Solution //
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while( fast && fast->next ){
            if( slow == fast ) return true;
            slow = slow->next;
            fast = fast->next->next;
        }
        return false;
    }
};