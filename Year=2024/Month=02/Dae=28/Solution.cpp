// Problem Link : https://leetcode.com/problems/find-bottom-left-tree-value/description/


// Solution //
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        int maxLvl = -1;
        int leftestVal = root->val;
        DFS(root, 0, maxLvl, leftestVal);
        return leftestVal;
    }

    void DFS(TreeNode *node, int currLvl, int &maxLvl, int &leftestVal){
        if( node ){
            if( currLvl > maxLvl ){
                maxLvl = currLvl;
                leftestVal = node->val;
            }
            DFS(node->left, currLvl+1, maxLvl, leftestVal);
            DFS(node->right, currLvl+1, maxLvl, leftestVal);
        }
    }
};
