// Problem Link : https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/description/


// Solution //
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        int n = nums.size();
        int currMax = -1;
        int ansRangeLen = INT_MAX;
        int ansRangeStart, ansRangeEnd;

        for(int idx=0; idx<n; idx++){
            pq.push({nums[idx][0], idx, 0});
            currMax = max(currMax, nums[idx][0]);
        }
        while( pq.size() == n ){
            auto top = pq.top(); pq.pop();
            int listIdx = top[1];
            int listEleIdx = top[2];
            int rangeStart = top[0];
            int rangeLen = currMax - rangeStart;
            if( rangeLen < ansRangeLen ){
                ansRangeLen = rangeLen;
                ansRangeStart = rangeStart;
                ansRangeEnd = currMax;
            }
            if( ++listEleIdx < nums[listIdx].size() ){
                pq.push({nums[listIdx][listEleIdx], listIdx, listEleIdx});
                currMax = max(currMax, nums[listIdx][listEleIdx]);
            }
        }
        return {ansRangeStart, ansRangeEnd};
    }
};