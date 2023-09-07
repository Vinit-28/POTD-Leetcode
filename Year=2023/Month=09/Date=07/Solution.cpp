// Problem Link : https://leetcode.com/problems/reverse-linked-list-ii/


// Solution //
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *lastNode = NULL;
        return helper(head, lastNode, 1, left, right);
    }

    ListNode *helper(ListNode *node, ListNode *&lastNode, int idx, int &left, int &right){
        if( node ){
            ListNode *res = helper(node->next, lastNode, idx+1, left, right);
            if( idx == right ){
                lastNode = node;
                return node;
            } else if( idx >= left && idx < right ){
                node->next = lastNode->next;
                lastNode->next = node;
                lastNode = node;
                return res;
            } else if( idx == left-1 ){
                node->next = res;
            }
            return node;
        }
        return NULL;
    }
};