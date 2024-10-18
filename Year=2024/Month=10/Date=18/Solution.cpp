// Problem Link : https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/description/


// Solution //
class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOR = 0;
        int ans = 0;
        int n = nums.size();
        for(auto &ele : nums) maxOR |= ele;
        for(int com=1; com<(1<<n); com++){
            int currOR = 0;
            for(int bitIdx=0; bitIdx<n; bitIdx++){
                int bit = (com>>bitIdx)&1;
                if( bit ) currOR |= nums[bitIdx];
            }
            ans += (currOR == maxOR);
        }
        return ans;
    }
};