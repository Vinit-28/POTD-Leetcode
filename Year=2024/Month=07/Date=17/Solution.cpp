// Problem Link : https://leetcode.com/problems/delete-nodes-and-return-forest/description/


// Solution //
class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> newRoots;
        unordered_set<int> to_del(begin(to_delete), end(to_delete));
        DFS(root, to_del, newRoots);
        if( !to_del.count(root->val) ){
            newRoots.push_back(root);
        }
        return newRoots;
    }

    TreeNode* DFS(TreeNode *node, unordered_set<int> &to_delete, vector<TreeNode*> &newRoots){
        if( node ){
            int val = node->val;
            if( to_delete.count(val) ){
                if( node->left ){
                    if( !to_delete.count(node->left->val) )
                        newRoots.push_back(node->left);
                    DFS(node->left, to_delete, newRoots);
                }
                if( node->right ){
                    if( !to_delete.count(node->right->val) )
                        newRoots.push_back(node->right);
                    DFS(node->right, to_delete, newRoots);
                }
                return NULL;
            } else{
                node->left = DFS(node->left, to_delete, newRoots);
                node->right = DFS(node->right, to_delete, newRoots);
                return node;
            }
        }
        return NULL;
    }
};