// Problem Link : https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/description/


// Solution //
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        map<int, vector<int>> valToIdxs;
        map<int, int> idxToVal;
        vector<vector<int>> arr;
        int n = nums.size();

        // Mapping value to Indices //
        for(int idx=0; idx<n; idx++){
            for(auto &val : nums[idx]){
                valToIdxs[val].push_back(idx);
            }
        }
        // Mapping index to an value //
        int idx = 0;
        for(auto [val, idxs] : valToIdxs){
            arr.push_back(idxs);
            idxToVal[idx++] = val;
        }

        // Sliding Window to find the minimum window containing all the ranges //
        int right = 0;
        int size = arr.size();
        int count = 0;
        int rangeMap[n]; memset(rangeMap, 0, sizeof(rangeMap));
        int ansRangeLen = INT_MAX;
        int ansRangeStart = -1, ansRangeEnd = -1;
        for(int left=0; left<size; left++){
            // Extend the window //
            while( right < size && count < n ){
                for(auto &idx : arr[right]){
                    count += (++rangeMap[idx] == 1);
                }
                right += 1;
            }
            if( count == n ){
                int rangeLen = idxToVal[right-1]-idxToVal[left];
                if( rangeLen < ansRangeLen ){
                    ansRangeLen = rangeLen;
                    ansRangeStart = idxToVal[left];
                    ansRangeEnd = idxToVal[right-1];
                }
            }
            // Removing the left from the window //
            for(auto &idx : arr[left]){
                count -= (--rangeMap[idx] == 0);
            }
        }
        return {ansRangeStart, ansRangeEnd};
    }
};