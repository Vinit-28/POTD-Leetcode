// Problem Link : https://leetcode.com/problems/split-linked-list-in-parts/description/


// Solution //
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len = getLength(head);
        int mod = len%k;
        ListNode *node = head;
        vector<ListNode*> lists;
        while( node ){
            int size = len/k + (mod>0? 1 : 0);
            lists.push_back(node);
            while( size-- > 1 ){
                node = node->next;
            }
            ListNode *next = node->next;
            node->next = NULL;
            node = next;
            mod -= 1;
        }
        int req = k - lists.size();
        for(int i=0; i<req; i++) lists.push_back(NULL);
        return lists;
    }

    int getLength(ListNode *node){
        int len = 0;
        while( node ) len++, node=node->next;
        return len;
    }
};