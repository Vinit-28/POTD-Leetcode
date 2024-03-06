// Problem Link : https://leetcode.com/problems/linked-list-cycle/description/


// Solution //
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while( fast && fast->next ){
            slow = slow->next;
            fast = fast->next->next;
            if( fast == slow ){
                return true;
            }
        }
        return false;
    }
};
