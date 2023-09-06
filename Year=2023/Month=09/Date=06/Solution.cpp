// Problem Link : https://leetcode.com/problems/split-linked-list-in-parts/


// Solution //
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len = 0, div, rem;
        ListNode *node = head, *next;
        vector<ListNode*> ans;

        // Calculating the length of the list //
        while( node ){
            len += 1;
            node = node->next;
        }

        // Main Logic //
        div = len/k;
        rem = len%k;
        node = head;
        for(int i=0;i<k;i++){
            int partitionLen = (rem<=0)? div : div + 1;
            rem = (rem<=0)? 0 : rem-1;
            ans.push_back(node);
            while( --partitionLen > 0 ){
                node = node->next;
            }
            if( node ){
                next = node->next;
                node->next = NULL;
                node = next;
            }
        }
        return ans;
    }
};