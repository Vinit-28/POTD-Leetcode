// Problem Link : https://leetcode.com/problems/remove-nodes-from-linked-list/description/


// Solution 1 -- Using Monotonic Stack //
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> st;
        ListNode *node = head, *newHead = head;
        while( node ){
            while( !st.empty() && st.top()->val < node->val ){
                st.pop();
            }
            if( st.empty() ) newHead = node;
            else st.top()->next = node;
            st.push(node);
            node = node->next;
        }
        return newHead;
    }
};

// Solution 2 -- Using Recursion //
class Solution {
public:
    ListNode* removeNodes(ListNode* node) {
        if( node->next == NULL ){
            return node;
        } else{
            ListNode *ll = removeNodes(node->next);
            if( ll->val <= node->val ){
                node->next =ll;
                return node;
            } else{
                return ll;
            }
        }
    }
};
