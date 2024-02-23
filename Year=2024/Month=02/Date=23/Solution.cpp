// Problem Link : https://leetcode.com/problems/cheapest-flights-within-k-stops/description/


// Solution //
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        queue<pair<int, int>> q;
        vector<pair<int, int>> graph[n+1];
        vector<int> prices(n, INT_MAX);
        int minPrice = INT_MAX;
        // Building the graph //
        for(auto &fd : flights){
            int u = fd[0], v = fd[1], p = fd[2];
            graph[u].push_back({v, p});
        }
        // Initialization //
        q.push({src, 0});
        prices[src] = 0;
        // BFS //
        while( !q.empty() && k>=0 ){
            int size = q.size();
            while( size-- > 0 ){
                auto td = q.front(); q.pop();
                int city = td.first, tct = td.second;
                for(auto &fd : graph[city]){
                    int tc = fd.first, tp = fd.second;
                    int newPrice = tct + tp;
                    if( tc == dst ){
                        minPrice = min(minPrice, newPrice);
                    } else if( newPrice < prices[tc] ){
                        prices[tc] = newPrice;
                        q.push({tc, newPrice});
                    }
                }
            }
            k -= 1;
        }
        return minPrice==INT_MAX? -1 : minPrice;
    }
};
