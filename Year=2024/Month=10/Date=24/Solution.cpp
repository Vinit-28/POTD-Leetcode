// Problem Link : https://leetcode.com/problems/flip-equivalent-binary-trees/description/


// Solution //
class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return helper(root1, root2);
    }

    bool helper(TreeNode *node1, TreeNode *node2){
        if( (!node1 && node2) || (node1 && !node2) ){
            return false;
        } else if( node1 && node2 ){
            if( node1->val != node2->val ) return false;
            return (
                helper(node1->left, node2->left) && helper(node1->right, node2->right)
            ) || (
                helper(node1->right, node2->left) && helper(node1->left, node2->right)
            );
        }
        return true; // Both NULL //
    }
};