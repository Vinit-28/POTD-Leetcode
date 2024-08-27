// Problem Link : https://leetcode.com/problems/binary-tree-postorder-traversal/description/



// Solution //
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> order;
        TreeNode *node = root;
        while( node ){
            // If Right subtree exists //
            if( node->right ){
                TreeNode *temp = node->right;
                TreeNode *lastNode = NULL;
                // Finding the left most node of the right subtree of node //
                while( temp && temp->left != node ){
                    lastNode = temp;
                    temp = temp->left;
                }
                if( temp ){ // If chain already exists /
                    temp->left = NULL;
                    node = node->left;
                } else{ // Making the chain //
                    lastNode->left = node;
                    order.push_back(node->val);
                    node = node->right;
                }
            } else{ 
                order.push_back(node->val);
                node = node->left;
            }
        }
        reverse(order.begin(), order.end());
        return order;
    }
};