// Problem Link : https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array/description/


// Solution //
class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int count = 0, sum = 0, n = nums.size();
        vector<int> ans;
        for(auto &ele : nums){
            int leftSum = sum;
            int rightSum = totalSum - (leftSum + ele);
            int left = ((count*ele) - leftSum);
            int right = (rightSum - ((n-count-1)*ele));
            ans.push_back(left + right);
            count += 1;
            sum += ele;
        }
        return ans;
    }
};