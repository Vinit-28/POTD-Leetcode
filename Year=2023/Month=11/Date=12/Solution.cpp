// Problem Link : https://leetcode.com/problems/bus-routes/description/


// Solution //
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        map<int, vector<int>> graph; // { station: {busIdx, busIdx,}, }
        int n = routes.size();
        // Making the graph //
        for(int i=0;i<n;i++){
            for(auto &station : routes[i]){
                graph[station].push_back(i);
            }
        }
        return BFS(routes, graph, source, target);
    }

    int BFS(vector<vector<int>> &routes, map<int, vector<int>> &graph, int src, int tar){
        if( src == tar ) return 0;
        queue<int> q; // { busIdx, } //
        int count = 1;
        bool isBusVisited[routes.size()];
        // Initializing the queue //
        memset(isBusVisited, false, sizeof(isBusVisited));
        for(auto &busIdx : graph[src]){
            q.push(busIdx);
            isBusVisited[busIdx] = true;
        }
        // Main Logic //
        while( !q.empty() ){
            int size = q.size();
            while( size-- > 0 ){
                auto busIdx = q.front();
                q.pop();
                for(auto &station : routes[busIdx]){
                    if( station == tar ){
                        return count;
                    } else{
                        for(auto &busIdx : graph[station]){
                            if( !isBusVisited[busIdx] ){
                                isBusVisited[busIdx] = true;
                                q.push(busIdx);
                            }
                        }
                    }
                }
            }
            count += 1;
        }
        return -1;
    }
};