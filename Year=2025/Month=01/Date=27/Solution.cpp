// Problem Link : https://leetcode.com/problems/course-schedule-iv/description/


// Solution //
class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int q = queries.size();
        int level = 0;
        vector<vector<int>> adj(n, vector<int>());
        vector<bool> ans(q);
        vector<int> in(n, 0);
        queue<int> que;
        vector<bitset<101>> dependencies(n, bitset<101>(0));

        for(auto &p : prerequisites){
            int u = p[0];
            int v = p[1];
            adj[u].push_back(v);
            in[v] += 1;
        }

        for(int node=0; node<n; node++){
            if( in[node]==0 ){
                que.push(node);
            }
        }
        while( que.empty()==false ){
            int size = que.size();
            while( size-- > 0 ){
                int node = que.front(); que.pop();
                dependencies[node].set(node);
                for(auto &cn : adj[node]){
                    dependencies[cn] |= dependencies[node];
                    if( --in[cn]==0 ){
                        que.push(cn);
                    }
                }
            }
            level += 1;
        }
        for(int qIdx=0; qIdx<q; qIdx++){
            auto &query = queries[qIdx];
            int u = query[0];
            int v = query[1];
            ans[qIdx] = dependencies[v].test(u);
        }
        return ans;
    }
};