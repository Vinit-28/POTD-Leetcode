// Problem Link : https://leetcode.com/problems/count-days-without-meetings/description/


// Solution //
class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        // Merging the overlapping intervals //
        int start = -1, end = -1;
        vector<vector<int>> meets;
        
        for(auto &meet : meetings){
            if( start == -1 ){
                start = meet[0], end = meet[1];
            } else if( end >= meet[0] ){
                end = max(end, meet[1]);
            } else{
                meets.push_back({start, end});
                start = meet[0];
                end = meet[1];
            }
        }
        meets.push_back({start, end});
        int freeDays = max(0, meets[0][0]-1);
        int n = meets.size();
        for(int idx=1; idx<n; idx++){
            freeDays += (meets[idx][0] - meets[idx-1][1] - 1);
        }
        freeDays += max(0, days - meets[n-1][1]);
        return freeDays;
    }
};