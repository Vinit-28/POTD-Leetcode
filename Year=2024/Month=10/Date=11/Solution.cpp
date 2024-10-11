// Problem Link : https://leetcode.com/problems/the-number-of-the-smallest-unoccupied-chair/description/


// Solution //
class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        vector<pair<int,int>> a, d;
        int n = times.size();
        for(int idx=0; idx<n; idx++){
            a.push_back({times[idx][0], idx});
            d.push_back({times[idx][1], idx});
        }
        sort(begin(a), end(a));
        sort(begin(d), end(d));
        int aIdx = 0, dIdx = 0;
        int mpp[n];
        priority_queue<int, vector<int>, greater<int>> pq;
        int charIdx = 0;
        while( aIdx < n ){
            if( a[aIdx].first < d[dIdx].first ){ // Someone is arriving //
                int personIdx = a[aIdx].second;
                if( pq.empty() ){
                    mpp[personIdx] = charIdx++;
                } else{
                    mpp[personIdx] = pq.top(); pq.pop();
                }
                if( personIdx == targetFriend ){
                    return mpp[personIdx];
                }
                aIdx += 1;
            } else{
                int personIdx = d[dIdx].second;
                int freeChairIdx = mpp[personIdx];
                pq.push(freeChairIdx);
                dIdx += 1;
            }
        }
        return -1;
    }
};