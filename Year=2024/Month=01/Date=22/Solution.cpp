// Problem Link : https://leetcode.com/problems/set-mismatch/description/


// Solution //
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        long sqSumExp = 0, sqSumActual = 0;
        int n = nums.size();
        long sumExp = 0, sumActual = 0;
        for(int i=0;i<n;i++){
            sqSumExp += ((i+1)*(i+1));
            sqSumActual += (nums[i]*nums[i]);
            sumExp += i+1;
            sumActual += nums[i];
        }
        long sqDiff = sqSumExp - sqSumActual;
        long diff = sumExp - sumActual;
        for(int i=0;i<n;i++){
            long sq = nums[i]*nums[i];
            if( (sq+sqDiff) > 0 ){
                int num = sqrt(sq+sqDiff);
                if( num*num == (sq+sqDiff) && num <= n && (num-nums[i]) == diff ){
                    return {nums[i], num};
                }
            }
        }
        return {-1, -1};
    }
};