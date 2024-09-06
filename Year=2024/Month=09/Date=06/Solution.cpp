// Problem Link : https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/description/


// Solution //
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int> st(begin(nums), end(nums));
        ListNode *newHead = NULL, *last = NULL;
        ListNode *node = head;
        while( node ){
            if( !st.count(node->val) ){
                if( newHead == NULL ) newHead = last = node;
                else last->next = node, last = last->next;
            }
            node = node->next;
        }
        if( last ) last->next = NULL;
        return newHead;
    }
};