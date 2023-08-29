// Problem Link : https://leetcode.com/problems/minimum-penalty-for-a-shop/


// Solution //
class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size(), idx = n, miniPenalty = INT_MAX;
        int prefixN[n], prefixY[n];
        prefixN[0] = customers[0] == 'N'? 1 : 0;
        prefixY[0] = customers[0] == 'Y'? 1 : 0;

        for(int i=1;i<n;i++){
            prefixN[i] = prefixN[i-1] + (customers[i] == 'N'? 1 : 0);
            prefixY[i] = prefixY[i-1] + (customers[i] == 'Y'? 1 : 0);
        }
        for(int i=0;i<n;i++){
            int penalty;
            if( i == 0 ){
                penalty = prefixY[n-1];
            } else{
                penalty = prefixN[i-1] + (prefixY[n-1] - prefixY[i-1]);
            }
            if( miniPenalty > penalty ){
                miniPenalty = penalty;
                idx = i;
            }
        }
        return (miniPenalty > prefixN[n-1])? n : idx;
    }
};