// Problem Link : https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/description/


// Solution //
class Solution {
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        int freq[10] = {0};
        int ans = 0;
        DFS(root, freq, ans);
        return ans;
    }

    void DFS(TreeNode *node, int freq[], int &ans){
        if( node ){
            freq[node->val] += 1;
            if( !node->left && !node->right ){
                ans += isPathPseudoPalindromic(freq);
            } else{
                DFS(node->left, freq, ans);
                DFS(node->right, freq, ans);
            }
            freq[node->val] -= 1;
        }
    }

    bool isPathPseudoPalindromic(int freq[]){
        int oddCount = 0;
        for(int i=1;i<10;i++){
            if( freq[i]&1 ){
                oddCount += 1;
            }
        }
        return oddCount <= 1;
    }
};