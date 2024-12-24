// Problem Link : https://leetcode.com/problems/find-minimum-diameter-after-merging-two-trees/description/


// Solution //
class Solution {
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n1 = edges1.size()+1;
        int n2 = edges2.size()+1;
        vector<vector<int>> adj1(n1, vector<int>());
        vector<vector<int>> adj2(n2, vector<int>());
        vector<int> degree1(n1, 0), degree2(n2, 0);
        // Build Graph1 //
        for(auto &edge : edges1){
            int u = edge[0], v = edge[1];
            adj1[u].push_back(v);
            adj1[v].push_back(u);
            degree1[u] += 1, degree1[v] += 1;
        }
        // Build Graph2 //
        for(auto &edge : edges2){
            int u = edge[0], v = edge[1];
            adj2[u].push_back(v);
            adj2[v].push_back(u);
            degree2[u] += 1, degree2[v] += 1;
        }
        int m1 = getMiddleNode(n1, adj1, degree1); // Middle Node of Graph1 //
        int m2 = getMiddleNode(n2, adj2, degree2); // Middle Node of Graph2 //
        int d1 = 0; // Existing Diameter of Graph1 //
        int d2 = 0; // Existing Diameter of Graph2 //
        int l1 = getLongestPathLen(m1, adj1, -1, d1); // Longest path Path Rooted at Middle Node in Graph1 //
        int l2 = getLongestPathLen(m2, adj2, -1, d2); // Longest path Path Rooted at Middle Node in Graph2 //
        // Answer will be either Existing Diameter of either of the Graphs or Longest Path of 
        // Middle Nodes of both the Graphs
        return max({d1, d2, l1+l2-1});
    }
    
    int getLongestPathLen(int node, vector<vector<int>> &adj, int parent, int &maxDiameter){
        int maxLen1 = 0;
        int maxLen2 = 0;
        for(auto &cn : adj[node]){
            if( cn != parent ){
                int pathLen = getLongestPathLen(cn, adj, node, maxDiameter);
                if( maxLen1 <= pathLen ){
                    maxLen2 = maxLen1;
                    maxLen1 = pathLen;
                } else if( maxLen2 < pathLen ){
                    maxLen2 = pathLen;
                }
            }
        }
        maxDiameter = max(maxDiameter, maxLen1 + maxLen2);
        return max(maxLen1, maxLen2)+1;
    }
    
    int getMiddleNode(int n, vector<vector<int>> &adj, vector<int> &degree){
        queue<int> que;
        vector<bool> isInQueue(n, false);
        for(int node=0; node<n; node++){
            if( degree[node] <= 1 ){
                que.push(node);
                isInQueue[node] = true;
            }
        }
        int middleNode = -1;
        while( que.empty()==false ){
            int node = que.front(); que.pop();
            middleNode = node;
            for(auto &cn : adj[node]){
                if( --degree[cn] <= 1 && isInQueue[cn] == false ){
                    que.push(cn);
                    isInQueue[cn] = true;
                }
            }
        }
        return middleNode;
    }
};