// Problem Link : https://leetcode.com/problems/sum-of-left-leaves/description/


// Solution //
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return DFS(root, '~');
    }

    int DFS(TreeNode *node, char side){
        if( node ){
            if( node->left==NULL && node->right==NULL ){
                return side=='l'? node->val : 0;
            }
            return DFS(node->left, 'l') + DFS(node->right, 'r');
        }
        return 0;
    }
};