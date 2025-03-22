// Problem Link : https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/description/


// Solution //
class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = recipes.size();
        vector<int> indegree(n, 0);
        map<string, vector<int>> adj;
        queue<string> que;
        vector<string> completedRecipes;
        for(int v=0; v<n; v++){
            for(auto &u: ingredients[v]){
                adj[u].push_back(v);
            }
            indegree[v] += (int)ingredients[v].size();
        }
        for(auto &ing: supplies){
            for(auto &cn: adj[ing]){
                if( --indegree[cn] == 0 ){
                    que.push(recipes[cn]);
                }
            }
        }

        while( que.empty()==false ){
            int size = que.size();
            while( size-- > 0 ){
                auto node = que.front(); que.pop();
                completedRecipes.push_back(node);
                for(auto &cn: adj[node]){
                    if( --indegree[cn] == 0 ){
                        que.push(recipes[cn]);
                    }
                }
            }
        }
        return completedRecipes;
    }
};