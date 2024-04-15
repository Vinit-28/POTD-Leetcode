// Problem Link : https://leetcode.com/problems/sum-root-to-leaf-numbers/description/


// Solution //
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        helper(root, 0, sum);
        return sum;
    }

    void helper(TreeNode *node, int num, int &sum){
        if( node ){
            int newNum = num*10+node->val;
            if( node->left==NULL && node->right==NULL ){
                sum += newNum;
            } else{
                helper(node->left, newNum, sum);
                helper(node->right, newNum, sum);
            }
        }
    }
};
