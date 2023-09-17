// Problem Link : https://leetcode.com/problems/shortest-path-visiting-all-nodes/description/


// Solution //
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int nodes = graph.size(), pathLen = 0;
        int allVisited = (1 << nodes) - 1;
        queue<vector<int>> q; // { {node, visitedNodes}, } //
        map<pair<int, int>, bool> hmap; // { {node, nodesVisited} : true, } //

        for(int i=0;i<nodes;i++){
            q.push({i, (1 << i)});
        }
        while( q.empty() == false ){
            int size = q.size();
            while( size > 0 ){
                auto v = q.front(); q.pop();
                int node = v[0], visitedNodes = v[1];
                for(auto &cn : graph[node]){
                    int mask = (1 << cn);
                    if( (visitedNodes | mask) == allVisited ){
                        return pathLen+1;
                    } else if( hmap.find({cn, (visitedNodes | mask)}) == hmap.end() ){
                        hmap[{cn, (visitedNodes | mask)}] = true;
                        q.push({cn, (visitedNodes | mask)});
                    }
                }
                size -= 1;
            }
            pathLen += 1;
        }
        return 0;
    }
};