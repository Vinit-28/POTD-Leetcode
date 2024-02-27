// Problem Link : https://leetcode.com/problems/diameter-of-binary-tree/description/


// Solution //
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        getDepth(root, ans);
        return ans;
    }

    int getDepth(TreeNode *node, int &ans){
        if( node ){
            int left = getDepth(node->left, ans);
            int right = getDepth(node->right, ans);
            ans = max(ans, (left + right));
            return max(left, right)+1;
        }
        return 0;
    }
};
