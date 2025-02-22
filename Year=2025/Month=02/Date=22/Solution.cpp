// Problem Link : https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/description/


// Solution //
class Solution {
public:
    TreeNode* recoverFromPreorder(string traversal) {
        auto levelAndNodes = getLevelAndNodes(traversal);
        int idx = 0;
        return buildTree(levelAndNodes, idx, 1);
    }
private:
    TreeNode *buildTree(vector<pair<int,int>> &levelAndNodes, int &idx, int depth){
        if( idx >= levelAndNodes.size() || levelAndNodes[idx].first != depth ){
            return NULL;
        } else{
            TreeNode *node = new TreeNode(levelAndNodes[idx++].second);
            node->left = buildTree(levelAndNodes, idx, depth+1);
            if( node->left ){
                node->right = buildTree(levelAndNodes, idx, depth+1);
            }
            return node;
        }
    }
    vector<pair<int,int>> getLevelAndNodes(string &traversal){
        int level = 1;
        int node = 0;
        vector<pair<int,int>> levelAndNodes;
        for(auto &ch : traversal){
            if( ch == '-' ){
                if( level != 0 && node != 0 ){
                    levelAndNodes.push_back({level, node});
                    level = 1;
                    node = 0;
                }
                level += 1;
            } else{
                node = (node*10)+(ch-'0');
            }
        }
        levelAndNodes.push_back({level, node});
        return levelAndNodes;
    }
};