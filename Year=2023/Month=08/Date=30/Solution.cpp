// Problem Link : https://leetcode.com/problems/minimum-replacements-to-sort-the-array/


// Solution //
class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0, lastEle = nums[n-1];
        for(int i=n-2;i>=0;i--){
            if( nums[i] <= lastEle ){
                lastEle = nums[i];
            } else{
                if( nums[i]%lastEle == 0 ){
                    ans += (nums[i]/lastEle)-1;
                } else{
                    long long steps = (nums[i]/lastEle);
                    ans += steps;
                    lastEle = nums[i]/(steps+1);
                }
            }
        }
        return ans;
    }
};