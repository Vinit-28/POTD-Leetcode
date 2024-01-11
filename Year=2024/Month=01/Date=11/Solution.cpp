// Problem Link : https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/description/


// Solution //
class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        int maxDiff = 0;
        DFS(root, root->val, root->val, maxDiff);
        return maxDiff;
    }

    void DFS(TreeNode *node, int mini, int maxi, int &maxDiff){
        if( node ){
            maxDiff = max({maxDiff, abs(node->val-mini), abs(node->val-maxi)});
            mini = min(mini, node->val);
            maxi = max(maxi, node->val);
            DFS(node->left, mini, maxi, maxDiff);
            DFS(node->right, mini, maxi, maxDiff);
        }
    }
};