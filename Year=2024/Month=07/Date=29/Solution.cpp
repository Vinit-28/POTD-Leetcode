// Problem Link : https://leetcode.com/problems/count-number-of-teams/description/


// Solution //
class Solution {
public:
    int numTeams(vector<int>& r) {
        int n = r.size();
        int teams = 0;
        for(int i=0; i<n; i++){
            int left = 0, right = 0;
            for(int j=0; j<n; j++){
                if( r[j] > r[i] ){
                    if( j<i ) left += 1;
                    else right += 1;
                }
            }
            teams += (left * ((n-i-1)-right));
            teams += (right * (i-left));
        }
        return teams;
    }
};