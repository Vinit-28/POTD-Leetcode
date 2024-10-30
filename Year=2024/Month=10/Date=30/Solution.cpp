// Problem Link : https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/description/


// Solution //
class Solution {
private:
    vector<int> getLIS(vector<int> &nums){
        int n = nums.size();
        vector<int> lis(n, 0);
        for(int i=0; i<n; i++){
            for(int j=i-1; j>=0; j--){
                if( nums[i] > nums[j] )
                    lis[i] = max(lis[j], lis[i]);
            }
            lis[i] += 1;
        }
        return lis;
    }

    vector<int> getLDS(vector<int> &nums){
        int n = nums.size();
        vector<int> lds(n, 0);
        for(int i=n-1; i>=0; i--){
            for(int j=i+1; j<n; j++){
                if( nums[i] > nums[j] )
                    lds[i] = max(lds[j], lds[i]);
            }
            lds[i] += 1;
        }
        return lds;
    }
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        auto lis = getLIS(nums);
        auto lds = getLDS(nums);
        int ans = INT_MAX;
        for(int i=1; i<n-1; i++){
            int peak = nums[i];
            int leftMax = -1, rightMax = -1;
            for(int j=0; j<i; j++){
                if( nums[j] < peak )
                    leftMax = max(leftMax, lis[j]);
            }
            for(int j=i+1; j<n; j++){
                if( nums[j] < peak )
                    rightMax = max(rightMax, lds[j]);
            }
            if( leftMax != -1 && rightMax != -1 ){
                int leftCount = i-leftMax;
                int rightCount = (n-i-1)-rightMax;
                ans = min(ans, leftCount + rightCount);
            }
        }
        return ans;
    }
};