// Problem Link : https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/description/


// Solution //
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int first = -1, last = -1;
        int mini = INT_MAX, maxi = -1;
        int idx = 1;
        ListNode *prev = head;
        ListNode *node = prev->next;
        ListNode *next = node->next;

        while( next ){
            // Critical Point //
            if( isCriticalPoint(prev, node, next) ){
                if( first == -1 ){
                    first = idx;
                } else{
                    mini = min(mini, idx-last);
                    maxi = idx-first;
                }
                last = idx;
            }
            prev = node;
            node = next;
            next = next->next;
            idx += 1;
        }
        if( maxi == -1 ) mini = -1;
        return {mini, maxi};
    }
private:
    bool isCriticalPoint(ListNode *prev, ListNode *node, ListNode *next){
        if( node->val > prev->val && node->val > next->val ) return true;
        if( node->val < prev->val && node->val < next->val ) return true;
        return false;
    }
};