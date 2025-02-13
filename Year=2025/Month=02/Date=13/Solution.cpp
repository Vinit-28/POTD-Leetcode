// Problem Link : https://leetcode.com/problems/minimum-operations-to-exceed-threshold-value-ii/description/


// Solution //
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long, vector<long>, greater<long>> pq(begin(nums), end(nums));
        int ops = 0;
        while( pq.size() >= 2 && pq.top() < k ){
            long min1 = pq.top(); pq.pop();
            long min2 = pq.top(); pq.pop();
            long newEle = min1*2+min2;
            pq.push(newEle);
            ops += 1;
        }
        return ops;
    }
};