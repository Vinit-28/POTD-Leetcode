// Problem Link : https://leetcode.com/problems/even-odd-tree/description/


// Solution //

class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        int level = 0;
        q.push(root);
        while( q.empty()==false ){
            int size = q.size();
            int prevValue = (level&1)? INT_MAX : INT_MIN;
            // Traversing all the nodes of the current level //
            while( size-- > 0 ){
                auto node = q.front(); q.pop();
                if( isNodeValueValid(level, node->val, prevValue) ){
                    prevValue = node->val;
                    if( node->left ){
                        q.push(node->left);
                    }
                    if( node->right ){
                        q.push(node->right);
                    }
                } else{
                    return false;
                }
            }
            level += 1;
        }
        return true;
    }

    bool isNodeValueValid(int level, int value, int prevValue){
        // Odd Level //
        if( level&1 ){
            if( value&1 || value >= prevValue ){
                return false;
            } 
        } else{ // Even Level //
            if( !(value&1) || value <= prevValue ){
                return false;
            }
        }
        return true;
    }
};
