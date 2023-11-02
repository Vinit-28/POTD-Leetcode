// Problem Link : https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/description/


// Solution //
class Solution {
public:
    int averageOfSubtree(TreeNode* root) {
        int count = 0;
        helper(root, count);
        return count;
    }

    pair<int, int> helper(TreeNode *node, int &count){
        if( node ){
            auto left = helper(node->left, count);
            auto right = helper(node->right, count);
            int nodes = left.first + right.first + 1;
            int sum = left.second + right.second + node->val;
            int avg = sum/nodes;
            if( avg == node->val ){
                count += 1;
            }
            return {nodes, sum};
        }
        return {0, 0};
    }
};