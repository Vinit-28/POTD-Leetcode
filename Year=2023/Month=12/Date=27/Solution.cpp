// Problem Link : https://leetcode.com/problems/minimum-time-to-make-rope-colorful/description/


// Solution //
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int timeReq = 0, prevSameColorTime = neededTime[0];
        for(int i=1;i<n;i++){
            if( colors[i] == colors[i-1] ){
                if( prevSameColorTime < neededTime[i] ){
                    timeReq += prevSameColorTime;
                    prevSameColorTime = neededTime[i];
                } else{
                    timeReq += neededTime[i];
                }
            } else{
                prevSameColorTime = neededTime[i];
            }
        }
        return timeReq;
    }
};