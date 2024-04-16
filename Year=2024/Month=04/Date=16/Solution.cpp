// Problem Link : https://leetcode.com/problems/add-one-row-to-tree/description/


// Solution //
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if( depth == 1 ){
            TreeNode *newRoot = new TreeNode(val, root, NULL);
            return newRoot;
        }
        helper(root, val, depth-1);
        return root;
    }

    void helper(TreeNode *node, int &val, int depth){
        if( node == NULL ) return;
        if( depth == 1 ){
            TreeNode *newLeftNode = new TreeNode(val, node->left, NULL);
            TreeNode *newRightNode = new TreeNode(val, NULL, node->right);
            node->left = newLeftNode;
            node->right = newRightNode;
        } else {
            helper(node->left, val, depth-1);
            helper(node->right, val, depth-1);
        }
    }
};