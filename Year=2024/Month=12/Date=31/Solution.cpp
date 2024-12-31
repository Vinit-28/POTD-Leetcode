// Problem Link : https://leetcode.com/problems/minimum-cost-for-tickets/description/


// Solution //
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int totalDays = 365;
        int dp[totalDays+1];
        int currDay = 365;
        int daysIdx = days.size()-1;
        while( currDay > 0 ){
            if( daysIdx >= 0 && currDay == days[daysIdx] ){
                int minCost = 1e9;
                // 1 Day pass //
                minCost = min(minCost, costs[0]+getCostAhead(dp, currDay+1, totalDays));
                // 7 Days pass //
                minCost = min(minCost, costs[1]+getCostAhead(dp, currDay+7, totalDays));
                // 30 Days pass //
                minCost = min(minCost, costs[2]+getCostAhead(dp, currDay+30, totalDays));
                dp[currDay] = minCost;
                daysIdx -= 1;
            } else{
                dp[currDay] = getCostAhead(dp, currDay+1, totalDays);
            }
            currDay -= 1;
        }
        return dp[1];
    }

    int getCostAhead(int dp[], int nextDay, int totalDays){
        return nextDay > totalDays? 0 : dp[nextDay];
    }
};