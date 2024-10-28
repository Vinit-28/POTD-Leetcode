// Problem Link : https://leetcode.com/problems/longest-square-streak-in-an-array/description/


// Solution //
class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(begin(nums), end(nums));
        map<int, int> mpp;
        int ans = 1;
        for(auto &ele : nums){
            int sq = sqrt(ele);
            if( sq*sq == ele ){
                mpp[ele] = mpp[sq] + 1;
            } else{
                mpp[ele] = 1;
            }
            ans = max(ans, mpp[ele]);
        }
        return ans==1? -1 : ans;
    }
};