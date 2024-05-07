// Problem Link : https://leetcode.com/problems/double-a-number-represented-as-a-linked-list/description/


// Solution 1 -- Using Monotonic Stack //
class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        int carry=0;
        helper(head, carry);
        if( carry > 0 ){
            ListNode *node = new ListNode(carry);
            node->next = head;
            head = node;
        }
        return head;
    }

    void helper(ListNode *node, int &carry){
        if( node ){
            helper(node->next, carry);
            int sum = (node->val * 2) + carry;
            if( sum >= 10 ){
                node->val = sum%10;
                carry = sum/10;
            } else{
                node->val = sum;
                carry = 0;
            }
        }
    }
};
