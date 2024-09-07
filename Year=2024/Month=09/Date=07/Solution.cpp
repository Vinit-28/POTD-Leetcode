// Problem Link : https://leetcode.com/problems/linked-list-in-binary-tree/description/


// Solution //
/*
    DP States would only be the {TreeNode, LinkedListHead}
*/
class Solution {
public:
    ListNode *llHead;
    map<pair<TreeNode*, ListNode*>, bool> dp;
    bool isSubPath(ListNode* head, TreeNode* root) {
        this->llHead = head;
        dp.clear();
        return helper(root, this->llHead);
    }

    bool helper(TreeNode *tNode, ListNode *llNode){
        if( !llNode ){
            return true;
        } else if( !tNode ){
            return false;
        } else if( llNode != llHead || dp.find({tNode, llNode}) == dp.end() ){
            bool res = false;
            if( tNode->val == llNode->val ){
                res = helper(tNode->left, llNode->next) || helper(tNode->right, llNode->next);
            }
            if( !res ){
                res = helper(tNode->left, llHead) || helper(tNode->right, llHead);
            }
            if( llHead == llNode ) dp[{tNode, llNode}] = res;
            else return res;
        }
        return dp[{tNode, llNode}];
    }
};