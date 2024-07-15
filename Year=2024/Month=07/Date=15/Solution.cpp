// Problem Link : https://leetcode.com/problems/create-binary-tree-from-descriptions/description/


// Solution //
class Solution {
private:
    TreeNode* getNode(int val, unordered_map<int, TreeNode*> &mpp){
        if( mpp.find(val) == mpp.end() ){
            mpp[val] = new TreeNode(val);
        }
        return mpp[val];
    }
public:
    TreeNode* createBinaryTree(vector<vector<int>>& des) {
        unordered_map<int, TreeNode*> mpp;
        unordered_map<int, bool> isRoot;
        TreeNode *root;
        for(auto &d : des){
            int p = d[0], c = d[1], l = d[2];
            TreeNode *parent = getNode(p, mpp), *child = getNode(c, mpp);
            if( l ) parent->left = child;
            else parent->right = child;
            isRoot[p] = true, isRoot[c] = false;
        }
        // Removing the child nodes from the parent list //
        for(auto &d : des){
            isRoot[d[1]] = false;
        }
        // Identifying the Root //
        for(auto &p : isRoot){
            if( p.second ){
                root = mpp[p.first];
                break;
            }
        }
        return root;
    }
};