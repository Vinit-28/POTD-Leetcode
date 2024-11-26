// Problem Link : https://leetcode.com/problems/find-champion-ii/description/


// Solution //
class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        int dependencies[n];
        memset(dependencies, 0, sizeof(dependencies));
        for(auto &edge : edges){
            int v = edge[1];
            dependencies[v] += 1;
        }
        int winner = -1;
        int winnerCount = 0;
        for(int node=0; node<n; node++){
            if( dependencies[node] == 0 ){
                winner = node;
                winnerCount += 1;
            }
        }
        return winnerCount==1? winner : -1;
    }
};