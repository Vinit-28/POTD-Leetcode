// Problem Link : https://leetcode.com/problems/reconstruct-itinerary/description/


// Solution //
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string, map<string, int>> graph;
        map<string, int> travelHistory;
        vector<string> order = {"JFK"};
        int totalTickets = tickets.size();
        // Making Graph //
        for(auto &ticket : tickets){
            graph[ticket[0]][ticket[1]] += 1;
        }
        // Solving Problem //
        DFS(graph, travelHistory, "JFK", order, totalTickets);
        // Return Ans //
        return order;
    }

    bool DFS(map<string, map<string, int>> &graph, map<string, int> &travelHistory, string node, vector<string> &order, int &totalTickets){
        if( order.size() == (totalTickets+1) ){
            return true;
        } else{
            for(auto &p : graph[node]){
                string cn = p.first;
                string key = node + "_" + cn;
                int occur = p.second;
                if( travelHistory[key] < occur ){
                    travelHistory[key] += 1;
                    order.push_back(cn);
                    if( DFS(graph, travelHistory, cn, order, totalTickets) ){
                        return true;
                    }
                    travelHistory[key] -= 1;
                    order.pop_back();
                }
            }            
        }
        return false;
    }
};