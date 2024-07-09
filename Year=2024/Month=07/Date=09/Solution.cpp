// Problem Link : https://leetcode.com/problems/average-waiting-time/description/


// Solution //
class Solution {
public:
    using ll = long long;
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();
        ll totalWait = 0;
        ll lastFree = 0;
        for(int i=0; i<n; i++){
            lastFree = max(lastFree, ll(customers[i][0]));
            ll waitingTime = (lastFree + customers[i][1]) - customers[i][0];
            totalWait += waitingTime;
            lastFree += customers[i][1];
        }
        return totalWait*1.0/n;
    }
};