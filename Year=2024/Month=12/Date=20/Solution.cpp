// Problem Link : https://leetcode.com/problems/reverse-odd-levels-of-binary-tree/description/


// Solution //
class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> que;
        int level = 0;
        que.push(root);
        while( que.empty()==false ){
            int size = que.size();
            vector<TreeNode*> levelNodes;
            while( size-- > 0 ){
                auto node = que.front(); que.pop();
                if( node->left ) que.push(node->left);
                if( node->right ) que.push(node->right);
                if( level&1 ) levelNodes.push_back(node);
            }
            if( level&1 ) reverseNodeValues(levelNodes);
            level += 1;
        }
        return root;
    }
    
private:
    void reverseNodeValues(vector<TreeNode*> &levelNodes){
        int i = 0, j = levelNodes.size()-1;
        while( i<j ){
            swap(levelNodes[i]->val, levelNodes[j]->val);
            i += 1;
            j -= 1;
        }
    }
};