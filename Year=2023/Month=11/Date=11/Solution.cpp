// Problem Link : https://leetcode.com/problems/design-graph-with-shortest-path-calculator/description/


// Solution //
class Graph {
public:
    map<int, vector<vector<int>>> graph;
    int n;
    Graph(int n, vector<vector<int>>& edges) {
        graph.clear();
        this->n = n;
        for(auto &edge : edges){
            graph[edge[0]].push_back({edge[1], edge[2]});
        }
    }
    
    void addEdge(vector<int> edge) {
        graph[edge[0]].push_back({edge[1], edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> hp;
        int distances[n];
        hp.push({0, node1});
        memset(distances, -1, sizeof(distances));
        while( !hp.empty() ){
            auto v = hp.top();
            hp.pop();
            int node = v[1], costTill = v[0];
            if( node == node2 ){
                return costTill;
            } else{
                for(auto &edge : graph[node]){
                    int cn = edge[0];
                    int newCost = costTill + edge[1];
                    if( distances[cn] == -1 ||  distances[cn] > newCost ){
                        distances[cn] = newCost;
                        hp.push({newCost, cn});
                    }
                }
            }
        }
        return -1;
    }
};