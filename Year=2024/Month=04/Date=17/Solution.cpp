// Problem Link : https://leetcode.com/problems/smallest-string-starting-from-leaf/description/


// Solution //
class Solution {
public:
    string ans;
    string smallestFromLeaf(TreeNode* root) {
        ans = "-1";
        DFS(root, "");
        return ans;
    }

    void DFS(TreeNode *node, string path){
        if( node == NULL ) return;
        path += getCharValue(node);
        if( node->left == NULL && node->right == NULL ){
            reverse(path.begin(), path.end());
            ans = ans=="-1"? path : min(ans, path);
        } else{
            DFS(node->left, path);
            DFS(node->right, path);
        }
    }

    char getCharValue(TreeNode *node){
        return node->val + 'a';
    }
};
