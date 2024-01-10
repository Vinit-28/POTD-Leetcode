// Problem Link : https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/description/


// Solution //
class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, bool> isInfected;
        unordered_map<int, vector<int>> graph;
        queue<int> q;
        int time = 0;

        DFS(root->left, root->val, graph);
        DFS(root->right, root->val, graph);
        isInfected[start] = true;
        q.push(start);

        while( !q.empty() ){
            int size = q.size();
            while( size-- > 0 ){
                auto node = q.front(); q.pop();
                for(auto &cn : graph[node]){
                    if( !isInfected[cn] ){
                        isInfected[cn] = true;
                        q.push(cn);
                    }
                }
            }
            time += 1;
        }
        return time-1;
    }

    void DFS(TreeNode *node, int &parent, unordered_map<int, vector<int>> &graph){
        if( node ){
            graph[parent].push_back(node->val);
            graph[node->val].push_back(parent);
            DFS(node->left, node->val, graph);
            DFS(node->right, node->val, graph);
        }
    }
};