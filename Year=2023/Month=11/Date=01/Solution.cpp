// Problem Link : https://leetcode.com/problems/find-mode-in-binary-search-tree/description/


// Solution //
class Solution {
public:
    vector<int> ans;
    int maxFreq;
    int currVal, currFreq;
    vector<int> findMode(TreeNode* root) {
        ans.clear();
        maxFreq = 0, currVal = INT_MAX, currFreq = 0;
        helper(root);
        return ans;
    }

    void helper(TreeNode *node){
        if( node ){
            helper(node->left);
            currFreq = (currVal == node->val)? currFreq+1 : 1;
            if( currFreq > maxFreq ){
                maxFreq = currFreq;
                ans = {node->val};
            } else if( currFreq == maxFreq ){
                ans.push_back(node->val);
            }
            currVal = node->val;
            helper(node->right);
        }
    }
};