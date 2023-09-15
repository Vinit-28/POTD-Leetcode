// Problem Link : https://leetcode.com/problems/min-cost-to-connect-all-points/description/


// Solution -- Prim's Algorithm to find the Cost of Minimum Spanning Tree //
class Solution {
public:
    int getDistanceBetweenTwoPoints(vector<int> &a, vector<int> &b){
        return abs(a[0] - b[0]) + abs(a[1] - b[1]);
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        // Prim's Algo //
        int currNode = 0, isVisited[n]; memset(isVisited, 0, sizeof(isVisited));
        int minDist = 0, edgesReq = n-1;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        while( edgesReq > 0 ){
            isVisited[currNode] = 1;
            // Finding the neighbours //
            for(int idx=0;idx<n;idx++){
                if( idx != currNode && isVisited[idx] == 0 ){
                    int v = idx, dist = getDistanceBetweenTwoPoints(points[currNode], points[idx]);
                    minHeap.push({dist, v}); // {distance, v} //
                }
            }
            // Selecting the closest unvisited neighbour //
            while( isVisited[minHeap.top()[1]] ){
                minHeap.pop();
            }
            auto minEdge = minHeap.top(); minHeap.pop();
            minDist += minEdge[0];
            currNode = minEdge[1];
            edgesReq -= 1;
        }
        // Return the ans //
        return minDist;
    }
};



// Solution -- Kruskal's Algorithm to find the Cost of Minimum Spanning Tree //
class DisjointSet{
    public:
        vector<int> parent;
        DisjointSet(int n){
            parent.resize(n, -1);
        }

        int findParent(int node){
            if( parent[node] == -1 ){
                return node;
            }
            return parent[node] = findParent(parent[node]);
        }

        void addEdge(int u, int v){
            int uParent = findParent(u);
            int vParent = findParent(v);
            parent[vParent] = uParent;
        }
};


class Solution {
public:
    int getDistanceBetweenTwoPoints(vector<int> &a, vector<int> &b){
        return abs(a[0] - b[0]) + abs(a[1] - b[1]);
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size(), edgesReq = n-1, minDist = 0;
        DisjointSet dsu(n);
        vector<vector<int>> edges; // { {distance, u, v}, } //
        // Finding the edges //
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int dist = getDistanceBetweenTwoPoints(points[i], points[j]);
                edges.push_back({dist, i, j});
            }
        }
        // Sorting the edges based on distance //
        sort(edges.begin(), edges.end());
        // Considering every edge that is not going to create a loop //
        for(auto &edge : edges){
            int dist = edge[0], u = edge[1], v = edge[2];
            // If this edge will create a loop //
            if( dsu.findParent(u) == dsu.findParent(v) ){
                // don't consider this edge //
            } else{ 
                // Considering the edge //
                dsu.addEdge(u, v);
                minDist += dist;
                edgesReq -= 1;
            }
            if( edgesReq <= 0 ){
                break;
            }
        }
        return minDist;
    }
};