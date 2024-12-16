// Problem Link : https://leetcode.com/problems/final-array-state-after-k-multiplication-operations-i/description/


// Solution //
class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        int n = nums.size();
        for(int i=0; i<n; i++){
            pq.push({nums[i], i});
        }
        while( k-- > 0 ){
            auto [ele, idx] = pq.top(); pq.pop();
            nums[idx] = ele*multiplier;
            pq.push({nums[idx], idx});
        }
        return nums;
    }
};