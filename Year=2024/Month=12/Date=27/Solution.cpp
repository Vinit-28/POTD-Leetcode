// Problem Link : https://leetcode.com/problems/best-sightseeing-pair/description/


// Solution //
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        int i = 0;
        int maxPairSum = 0;
        for(int j=1; j<n; j++){
            int dist = j-i;
            int pairSum = values[i] + values[j] - dist;
            maxPairSum = max(maxPairSum, pairSum);
            if((values[i]-dist) <= values[j]){
                i = j;
            }
        }
        return maxPairSum;
    }
};