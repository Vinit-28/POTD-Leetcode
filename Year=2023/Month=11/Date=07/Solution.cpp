// Problem Link : https://leetcode.com/problems/eliminate-maximum-number-of-monsters/description/


// Solution //
class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        int reachTime[n];
        int kills = 0, nextKillOn = 0;
        for(int i=0;i<n;i++){
            reachTime[i] = ceil(1.0*dist[i]/speed[i]);
        }
        sort(reachTime, reachTime+n);
        for(int i=0;i<n;i++){
            if( nextKillOn >= reachTime[i] ){
                break;
            }
            kills += 1;
            nextKillOn += 1;
        }
        return kills;
    }
};