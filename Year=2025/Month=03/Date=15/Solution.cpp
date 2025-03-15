// Problem Link : https://leetcode.com/problems/house-robber-iv/description/


// Solution //
class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int l = 0, u = 1e9;
        while( l+1 < u ){
            int mid = (l+u)/2;
            if( isPossible(nums, k, mid) ){
                u = mid;
            } else{
                l = mid;
            }
        }
        return u;
    }
private:
    bool isPossible(vector<int> &nums, int k, int mid){
        int cons = 0;
        for(auto &ele : nums){
            if( ele > mid ){
                k -= ceil(cons*1.0/2);
                cons = 0;
            } else{
                cons += 1;
            }
        }
        k -= ceil(cons*1.0/2);
        return k <= 0;
    }
};