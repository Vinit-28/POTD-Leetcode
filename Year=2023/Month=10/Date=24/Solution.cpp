// Problem Link : https://leetcode.com/problems/find-largest-value-in-each-tree-row/description/


// Solution //
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> q;
        int level = 0;
        if( root ){
            q.push(root);
            while( q.empty()==false ){
                int size = q.size();
                int maxi = -1;
                bool flag = false;
                while( size-- > 0 ){
                    auto node = q.front();
                    q.pop();
                    if( node->left ){
                        q.push(node->left);
                    }
                    if( node->right ){
                        q.push(node->right);
                    }
                    if( !flag || maxi < node->val ){
                        maxi = node->val;
                        flag = true;
                    }
                }
                ans.push_back(maxi);
                level += 1;
            }
        }
        return ans;
    }
};