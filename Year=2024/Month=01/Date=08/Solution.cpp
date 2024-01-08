// Problem Link : https://leetcode.com/problems/range-sum-of-bst/description/


// Solution //
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        return helper(root, low, high);
    }

    int helper(TreeNode *node, int &low, int &high){
        if( node ){
            int sum = 0;
            if( node->val >= low && node->val <= high ) sum += node->val;
            if( node->val >= low ) sum += helper(node->left, low, high);
            if( node->val <= high ) sum += helper(node->right, low, high);
            return sum;
        }
        return 0;
    }
};
