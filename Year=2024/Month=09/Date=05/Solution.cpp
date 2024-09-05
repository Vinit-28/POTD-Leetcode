// Problem Link : https://leetcode.com/problems/find-missing-observations/description/


// Solution //
class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int totalSum = mean * (m+n);
        int currSum = accumulate(begin(rolls), end(rolls), 0);
        int remSum = totalSum - currSum;
        if( remSum < n ) return {};
        vector<int> missingVal(n);
        for(int i=0; i<n; i++){
            int remCells = n - i - 1;
            missingVal[i] = min(6, remSum - remCells);
            remSum -= missingVal[i];
        } 
        if( remSum > 0 ) return {};
        return missingVal;
    }
};