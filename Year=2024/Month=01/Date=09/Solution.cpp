// Problem Link : https://leetcode.com/problems/leaf-similar-trees/description/


// Solution //
class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> t1, t2;
        DFS(root1, t1);
        DFS(root2, t2);
        return t1 == t2;
    }

    void DFS(TreeNode *node, vector<int> &t){
        if( node ){
            if( isLeafNode(node) ){
                t.push_back(node->val);
            } else{
                DFS(node->left, t);
                DFS(node->right, t);
            }
        }
    }

    bool isLeafNode(TreeNode *node){
        return (!node->left && !node->right);
    }
};
