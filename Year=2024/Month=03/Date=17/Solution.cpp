// Problem Link : https://leetcode.com/problems/insert-interval/description/


// Solution //
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> mergedIntervals;
        int start = newInterval[0], end = newInterval[1];
        int n = intervals.size(), idx = 0;
        while( idx < n && intervals[idx][1] < start ){
            mergedIntervals.push_back(intervals[idx]);
            idx += 1;
        }
        while( idx < n && intervals[idx][0] <= end ){
            start = min(intervals[idx][0], start);
            end = max(intervals[idx][1], end);
            idx += 1;
        }
        mergedIntervals.push_back({start, end});
        while( idx<n ){
            mergedIntervals.push_back(intervals[idx]);
            idx += 1;
        }
        return mergedIntervals;
    }
};