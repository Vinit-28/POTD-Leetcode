// Problem Link : https://leetcode.com/problems/minimum-amount-of-time-to-collect-garbage/description/


// Solution //
class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int totalTime = 0, n = garbage.size();;
        vector<char> trucks = {'M', 'G', 'P'};
        for(auto &truck : trucks){
            int time = 0, travelCost = 0;
            for(int i=0;i<n;i++){
                int occur = count(garbage[i].begin(), garbage[i].end(), truck);
                if( occur > 0 ){
                    time += travelCost;
                    time += occur;
                    travelCost = 0;
                }
                travelCost += i==n-1? 0 : travel[i];
            }
            totalTime += time;
        }
        return totalTime;
    }
};