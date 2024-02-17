// Problem Link : https://leetcode.com/problems/furthest-building-you-can-reach/description/


// Solution //
class Solution {
public:
    bool isValid(long bricks, long totalSum, long ladderSum){
        long brickSum = totalSum - ladderSum;
        return bricks >= brickSum;
    }

    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> pq;
        long totalSum = 0, ladderSum = 0;
        int n = heights.size();
        for(int i=1;i<n;i++){
            int diff = heights[i] - heights[i-1];
            if( diff > 0 ){
                if( pq.size() < ladders ){
                    pq.push(diff);
                    ladderSum += diff;
                } else if( !pq.empty() && pq.top() < diff ){
                    int minDiff = pq.top(); pq.pop();
                    pq.push(diff);
                    ladderSum -= minDiff, ladderSum += diff;
                }
                totalSum += diff;
                if( !isValid(bricks, totalSum, ladderSum) ){
                    return i-1;
                }
            }
        }
        return n-1;
    }
};
