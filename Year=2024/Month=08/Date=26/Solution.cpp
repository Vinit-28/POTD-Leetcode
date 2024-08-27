// Problem Link : https://leetcode.com/problems/n-ary-tree-postorder-traversal/description/



// Solution //
class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> ans;
        DFS(root, ans);
        return ans;
    }

    void DFS(Node *node, vector<int> &ans){
        if( node ){
            for(auto &child : node->children){
                DFS(child, ans);
            }
            ans.push_back(node->val);
        }
    }
};