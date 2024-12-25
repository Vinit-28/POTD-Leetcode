// Problem Link : https://leetcode.com/problems/find-largest-value-in-each-tree-row/description/


// Solution //
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if( root == NULL ) return {};
        vector<int> ans;
        queue<TreeNode*> que;
        que.push(root);
        while( que.empty()==false ){
            int size = que.size();
            int maxNodeValue = que.front()->val;
            while( size-- > 0 ){
                TreeNode *node = que.front(); que.pop();
                maxNodeValue = max(maxNodeValue, node->val);
                if( node->left ) que.push(node->left);
                if( node->right ) que.push(node->right);
            }
            ans.push_back(maxNodeValue);
        }
        return ans;
    }
};