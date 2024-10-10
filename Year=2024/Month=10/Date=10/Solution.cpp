// Problem Link : https://leetcode.com/problems/maximum-width-ramp/description/


// Solution //
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        map<int, int> mpp;
        int n = nums.size();
        int ans = 0;
        for(int i=n-1; i>=0; i--){
            int ele = nums[i];
            auto it = mpp.lower_bound(ele);
            if( it != mpp.end() ){
                // cout<<"For "<<ele<<" at "<<i<<" :: "<<it->first<<" at "<<it->second<<endl;
                ans = max(ans, it->second-i);
                mpp[ele] = it->second;
            } else{
                mpp[ele] = i;
            }
        }
        return ans;   
    }
};