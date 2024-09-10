// Problem Link : https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/description/


// Solution //
class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode *node = head;
        while( node ){
            ListNode *next = node->next;
            if( next ){
                ListNode *next = node->next;
                int a = node->val, b = next->val;
                int val = gcd(a, b);
                ListNode *newNode = new ListNode(val);
                node->next = newNode;
                newNode->next = next;
            }
            node = next;
        }
        return head;
    }
};