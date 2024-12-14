// Problem Link : https://leetcode.com/problems/continuous-subarrays/description/


// Solution //
using ll = long long;
class Solution {
public:
    ll continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        int right = 0;
        ll ans = 0;
        deque<int> mini, maxi;
        int k = 2;
        
        for(int left=0; left<n; left++){
            
            if( !mini.empty() && mini.front() < left ) mini.pop_front();
            if( !maxi.empty() && maxi.front() < left ) maxi.pop_front();
            
            while( right < n && isValid(nums, k, left, right, mini, maxi) ){
                // Maintain the mini //
                while( !mini.empty() && nums[mini.back()] >= nums[right] ){
                    mini.pop_back();
                }
                // Maintain the maxi //
                while( !maxi.empty() && nums[maxi.back()] <= nums[right] ){
                    maxi.pop_back();
                }
                mini.push_back(right);
                maxi.push_back(right);
                right += 1;
            }
            
            int len = right - left;
            ans += len;
        }
        return ans;
    }

private:
    bool isValid(vector<int> &nums, int k, int left, int right, deque<int> &mini, deque<int> &maxi){
        if( !mini.empty() && abs(nums[mini.front()]-nums[right]) > k ) return false;
        if( !maxi.empty() && abs(nums[maxi.front()]-nums[right]) > k ) return false;
        return true;
    }
};