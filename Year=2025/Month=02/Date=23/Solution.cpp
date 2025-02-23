// Problem Link : https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/description/


// Solution //
class Solution {
private:
    int preMpp[31];
    int postMpp[31];
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int n = pre.size();
        for(int i=0; i<n; i++){
            preMpp[pre[i]] = i;
            postMpp[post[i]] = i;
        }
        return buildTree(pre, post, 0, n-1, 0, n-1);
    }
private:
    TreeNode *buildTree(vector<int> &pre, vector<int> &post, int prel, int prer, int postl, int postr){
        if( prel > prer ){
            return NULL;
        } else if( prel == prer ){
            return new TreeNode(pre[prel]);
        } else{
            TreeNode *node = new TreeNode(pre[prel]);
            int leftNodeVal = pre[prel+1];
            int leftNodeIdx = postMpp[leftNodeVal];
            int leftCount = leftNodeIdx - postl + 1;
            node->left = buildTree(pre, post, prel+1, prel+leftCount, postl, leftNodeIdx);
            node->right = buildTree(pre, post, prel+leftCount+1, prer, leftNodeIdx+1, postr-1);
            return node;
        }
    }
};