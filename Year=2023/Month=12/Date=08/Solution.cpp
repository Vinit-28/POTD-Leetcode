// Problem Link : https://leetcode.com/problems/construct-string-from-binary-tree/description/

// Solution //
class Solution {
public:
    string tree2str(TreeNode* node) {
        if( node ){
            string ans = to_string(node->val);
            if( node->left && node->right ){
                ans += "(" + tree2str(node->left) + ")";
                ans += "(" + tree2str(node->right) + ")";
            } else if( !node->left && node->right ){
                ans += "(" + tree2str(node->left) + ")";
                ans += "(" + tree2str(node->right) + ")";
            } else if( node->left && !node->right ){
                ans += "(" + tree2str(node->left) + ")";
            }
            return ans;
        }
        return "";
    }
};
