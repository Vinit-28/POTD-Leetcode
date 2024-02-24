// Problem Link : https://leetcode.com/problems/find-all-people-with-secret/description/


// Solution //
class DSU{
    public:
        map<int, int> parents;
        DSU(){
            parents.clear();
        }

        void connectNodes(int u, int v, bool knowsSecret[]){
            int up = getParent(u);
            int vp = getParent(v);
            if( up != vp ){
                if( knowsSecret[vp] ){
                    parents[up] = vp;
                } else{
                   parents[vp] = up; 
                }
            }
        }

        int getParent(int node){
            if( parents.find(node) == parents.end() ){
                return node;
            }
            return parents[node] = getParent(parents[node]);
        }
};

class Solution {
public:
    static bool comp(vector<int>&a, vector<int>&b){
        return a[2]<b[2];
    }

    vector<int> findAllPeople(int n, vector<vector<int>>& ms, int fp) {
        // Pre-Processing //
        sort(ms.begin(), ms.end(), comp);
        // Declaration //
        int totalMeets = ms.size();
        bool knowsSecret[n]; memset(knowsSecret, false, sizeof(knowsSecret));
        vector<int> personsKnowsSecret;
        // Initialization //
        knowsSecret[0] = knowsSecret[fp] = true;
        // Main Logic //
        for(int meetIdx=0;meetIdx<totalMeets;){
            int from = meetIdx, to = meetIdx;
            DSU dsu;
            // Current time meetings //
            while( to<totalMeets && ms[from][2] == ms[to][2] ){
                int u = ms[to][0], v = ms[to][1];
                dsu.connectNodes(u, v, knowsSecret);
                to += 1;
            }

            for(int idx=from;idx<to;idx++){
                int u = ms[idx][0], v = ms[idx][1];
                int parent = dsu.getParent(u);
                knowsSecret[u] = knowsSecret[v] = knowsSecret[parent];
            }
            meetIdx = to;
        }
        for(int person=0;person<n;person++){
            if( knowsSecret[person] ){
                personsKnowsSecret.push_back(person);
            }
        }
        return personsKnowsSecret;
    }
};