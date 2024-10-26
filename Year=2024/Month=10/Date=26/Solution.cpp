// Problem Link : https://leetcode.com/problems/height-of-binary-tree-after-subtree-removal-queries/description/


// Solution //
class Solution {
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        unordered_map<int, vector<pair<int,int>>> levelMax;
        unordered_map<int, int> valLevel;
        vector<int> ans;
        DFS(root, 0, levelMax, valLevel);
        for(auto &q : queries){
            int level = valLevel[q];
            if( levelMax[level][0].second == q ){
                if( levelMax[level].size() == 1 ) ans.push_back(level-1);
                else ans.push_back(levelMax[level][1].first+level-1);
            } else{
                ans.push_back(levelMax[level][0].first+level-1);
            }
        }
        return ans;
    }

    int DFS(TreeNode *node, int level, unordered_map<int, vector<pair<int,int>>> &levelMax, unordered_map<int, int> &valLevel){
        if( node ){
            int left = DFS(node->left, level+1, levelMax, valLevel);
            int right = DFS(node->right, level+1, levelMax, valLevel);
            int maxHeight = max(left, right)+1;
            valLevel[node->val] = level;
            if( levelMax[level].size() < 2 ){
                levelMax[level].push_back({maxHeight, node->val});
                auto &arr = levelMax[level];
                if( arr.size() == 2 && arr[0].first < arr[1].first ) swap(arr[0], arr[1]);
            } else if( levelMax[level][0].first <= maxHeight ){
                swap(levelMax[level][0], levelMax[level][1]);
                levelMax[level][0] = {maxHeight, node->val};
            } else if( levelMax[level][1].first < maxHeight ){
                levelMax[level][1] = {maxHeight, node->val};
            }
            return maxHeight;
        }
        return 0;
    }
};