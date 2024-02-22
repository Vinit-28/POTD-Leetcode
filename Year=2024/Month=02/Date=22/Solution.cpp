// Problem Link : https://leetcode.com/problems/find-the-town-judge/description/


// Solution //
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int trustLevel[n+1];
        memset(trustLevel, 0, sizeof(trustLevel));
        for(auto &t : trust){
            int p1 = t[0], p2 = t[1];
            trustLevel[p2] += 1;
            trustLevel[p1] = INT_MIN;
        }   
        for(int i=1;i<=n;i++){
            if( trustLevel[i] == n-1 ){
                return i;
            }
        }
        return -1;
    }
};