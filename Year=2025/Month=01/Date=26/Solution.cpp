// Problem Link : https://leetcode.com/problems/maximum-employees-to-be-invited-to-a-meeting/description/


// Solution //
class Solution {
public:
    int maximumInvitations(vector<int> &fav) {
        // Declaration //
        set<vector<int>> locks; // {{a <--> b}, } //
        int totalNodes = fav.size();
        int visitedTime[totalNodes];
        int currTime = 1;
        vector<int> revAdj[totalNodes]; // { v:{u1, u2, u3}, }
        int acyclicChainSize = 0;
        int cyclicChainSize = 0;
        int maxChainSize;
        // Initialization //
        memset(visitedTime, -1, sizeof(visitedTime));
        for(int u=0; u<totalNodes; u++){
            int v = fav[u];
            // a <--> b //
            if( fav[v] == u ){
                vector<int> lock;
                if( u<v ) lock = {u, v};
                else lock = {v, u};
                locks.insert(lock);
            } else{
                revAdj[v].push_back(u);
            }
        }
        // Calculating the longest chain for every lock //
        for(auto &lock : locks){
            int a = lock[0], b = lock[1];
            int chainA = DFS(a, revAdj, visitedTime);
            int chainB = DFS(b, revAdj, visitedTime);
            acyclicChainSize += (chainA + chainB);
        }
        // Finding the length of the longest cyclic chain //
        for(int node=0; node<totalNodes; node++){
            currTime = findCycle(node, revAdj, visitedTime, currTime, currTime, cyclicChainSize)+1;
            // currTime += cyclicChainSize; // Any Arbitary Value //
        }
        // Getting the maximum of Acyclic Chain & Cyclic Chain //
        maxChainSize = max(acyclicChainSize,cyclicChainSize);
        return maxChainSize;
    }

    int DFS(int node, vector<int> revAdj[], int visitedTime[]){
        visitedTime[node] = 0;
        int maxChain = 0;
        for(auto &cn : revAdj[node]){
            maxChain = max(maxChain, DFS(cn, revAdj, visitedTime));
        }
        return maxChain+1;
    }

    int findCycle(int node, vector<int> revAdj[], int visitedTime[], int &startTime, int currTime, int &cyclicChainSize){
        if( visitedTime[node] == -1 ){
            visitedTime[node] = currTime;
            int maxTime = currTime;
            for(auto &cn : revAdj[node]){
                maxTime = max(maxTime, findCycle(cn, revAdj, visitedTime, startTime, currTime+1, cyclicChainSize));
            }
            return maxTime;
        } else if( visitedTime[node] >= startTime ){
            cyclicChainSize = max(cyclicChainSize, (currTime - visitedTime[node]));
        }
        return currTime;
    }
};