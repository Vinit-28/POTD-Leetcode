// Problem Link : https://leetcode.com/problems/constrained-subsequence-sum/description/


// Solution //
class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        deque<pair<int, int>> que;
        int ans = INT_MIN;
        que.push_back({nums.back(), nums.size()-1});
        for(int i=nums.size()-2;i>=0;i--){
            if( (que.front().second-i) > k ){
                que.pop_front();
            }
            int sum = max(nums[i], nums[i] + que.front().first);
            while( !que.empty() && que.back().first < sum ){
                que.pop_back();
            }
            que.push_back({sum, i});
            ans = max(ans, que.front().first);
        }
        return ans;
    }
};