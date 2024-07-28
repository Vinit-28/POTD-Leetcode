// Problem Link : https://leetcode.com/problems/second-minimum-time-to-reach-destination/description/


// Solution //
class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> bestTwo(n+1);
        vector<int> adj[n+1];
        queue<int> q;
        // Building the Adjacency List //
        for(auto &edge : edges){
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // BFS //
        int steps = 0;
        q.push(1);
        while( q.empty()==false ){
            int size = q.size();
            while( size-- > 0 ){
                int node = q.front(); q.pop();
                if( bestTwo[node].size()<=1 ) bestTwo[node].push_back(steps);
                else if( bestTwo[node][0] != bestTwo[node][1] && bestTwo[node][1] <= steps ) continue;
                else bestTwo[node][1] = steps;
                // Visiting the neighbours //
                for(auto &cn : adj[node]){
                    if( bestTwo[cn].size() < 2 || bestTwo[cn][0] == bestTwo[cn][1] ){
                        q.push(cn);
                    }
                }
            }
            steps += 1;
        }
        int stepsReq = (bestTwo[n][0]==bestTwo[n][1]? bestTwo[n][1]+2 : min(bestTwo[n][0]+2, bestTwo[n][1]));
        int timeReq = getTotalTimeReq(time, change, stepsReq);
        return timeReq;
    }   

    int getTotalTimeReq(int distTime, int changeTime, int stepsReq){
        // cout<<distTime<<" "<<changeTime<<" "<<stepsReq<<endl;
        bool signal = true;
        int steps = 0;
        int dist = 0;
        int prevDist = dist;
        int time = 0;
        while( steps < stepsReq ){
            time += 1;
            dist += (dist%distTime!=0 || signal);
            signal = (time%changeTime==0? !signal : signal);
            steps += (prevDist!=dist && dist%distTime==0);
            prevDist = dist;
        } 
        return time;
    }
};