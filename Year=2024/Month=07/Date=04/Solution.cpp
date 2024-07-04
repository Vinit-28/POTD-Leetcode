// Problem Link : https://leetcode.com/problems/merge-nodes-in-between-zeros/description/


// Solution //
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode *newHead = NULL, *lastNode = NULL;
        ListNode *currNode = head->next;
        int sum = 0;
        while( currNode ){
            if( currNode->val == 0 ){
                ListNode *newNode = new ListNode(sum);
                if( newHead == NULL ) newHead = lastNode = newNode;
                else lastNode->next = newNode, lastNode = newNode;
                sum = 0;
            } else{
                sum += currNode->val;
            }
            currNode = currNode->next;
        }
        return newHead;
    }
};