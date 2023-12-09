// Problem Link : https://leetcode.com/problems/binary-tree-inorder-traversal/description/



// Solution //
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        helper(root, ans);
        return ans;    
    }

    void helper(TreeNode *node, vector<int> &ans){
        if( node ){
            helper(node->left, ans);
            ans.push_back(node->val);
            helper(node->right, ans);
        }
    }
};