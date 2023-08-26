// Problem Link : https://leetcode.com/problems/maximum-length-of-pair-chain/


// Solution //
class Solution {
public:
    static bool comp(vector<int> a, vector<int> b){
        return a[1] < b[1];
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        // Sorting in Descending Sorder of Right Values //
        sort(pairs.begin(), pairs.end(), comp);
        int ans = 1, prevPairIdx = 0, n = pairs.size();
        
        for(int i=1;i<n;i++){
            auto currPair = pairs[i];
            if( currPair[0] > pairs[prevPairIdx][1] ){
                prevPairIdx = i;
                ans += 1;
            }
        }
        return ans;
    }
};