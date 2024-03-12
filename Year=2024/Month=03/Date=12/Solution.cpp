// Problem Link : https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/description/


// Solution //
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        // Declaration //
        map<int, ListNode*> mpp; // { sum:Node, } //
        int sum = 0;
        ListNode *node = head;
        ListNode *newHead = head;
        // Initialization //
        mpp[0] = NULL;
        // Logic //
        while( node != NULL ){
            sum += node->val;
            cout<<sum<<endl;
            if( mpp.find(sum) != mpp.end() ){
                ListNode *nd = (mpp[sum]==NULL)? newHead : mpp[sum]->next;
                int tempSum = sum;
                while( nd != node ){
                    tempSum += nd->val;
                    mpp.erase(tempSum);
                    nd = nd->next;
                }
                if( mpp[sum] == NULL ){
                    newHead = node->next;
                } else{
                    mpp[sum]->next = node->next;
                }
            } else{
                mpp[sum] = node;
            }
            node = node->next;
        }
        return newHead;
    }
};