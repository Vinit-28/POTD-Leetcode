// Problem Link : https://leetcode.com/problems/min-cost-climbing-stairs/description/


// Solution //
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int next1 = cost[n-2], next2 = cost[n-1];
        for(int i=n-3;i>=0;i--){
            int c1 = (cost[i] + min(next1, next2));
            next2 = next1, next1 = c1;
        }
        return min(next1, next2);
    }
};