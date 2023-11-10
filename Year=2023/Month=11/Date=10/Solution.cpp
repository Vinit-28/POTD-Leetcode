// Problem Link : https://leetcode.com/problems/restore-the-array-from-adjacent-pairs/description/


// Solution //
class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& ap) {
        // Declaration //
        map<int, vector<int>> graph;
        vector<int> ans;
        int n = ap.size(), root;
        map<int, bool> isVisited; 
        // Initialization //
        for(auto &p : ap){
            graph[p[0]].push_back(p[1]);
            graph[p[1]].push_back(p[0]);
        }
        // Find the first/root element //
        for(auto &p : graph){
            if( p.second.size() == 1 ){
                root = p.first;
                break;
            }
        }
        // Finding the next nodes/elements //
        DFS(graph, ans, isVisited, root);
        return ans;
    }

    // Doing DFS to find next nodes/elements //
    void DFS(map<int, vector<int>> &graph, vector<int> &arr, map<int, bool> &isVisited, int node){
        arr.push_back(node);
        isVisited[node] = true;
        for(auto &cn : graph[node]){
            if( !isVisited[cn] ){
                DFS(graph, arr, isVisited, cn);
            }
        }
    }
};