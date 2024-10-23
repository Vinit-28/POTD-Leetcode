// Problem Link : https://leetcode.com/problems/cousins-in-binary-tree-ii/


// Solution //
class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode*> q1, q2;
        q1.push(root);
        q2.push(root);
        while( q1.empty()==false ){
            int size = q1.size();
            int nextLevelSum = 0;
            while( size-- > 0 ){
                auto node = q1.front();
                q1.pop();
                if( node->left ) nextLevelSum += node->left->val, q1.push(node->left);
                if( node->right ) nextLevelSum += node->right->val, q1.push(node->right);
            }
            size = q2.size();
            while( size-- > 0 ){
                auto node = q2.front();
                q2.pop();
                int childSum = 0;
                // Pushing Next Level //
                if( node->left ) childSum += node->left->val, q2.push(node->left);
                if( node->right ) childSum += node->right->val, q2.push(node->right);
                // Updating node values //     
                if( node->left ) node->left->val = nextLevelSum - childSum;
                if( node->right ) node->right->val = nextLevelSum - childSum;
            }
        }
        root->val = 0;
        return root;
    }
};