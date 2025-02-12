// Problem Link : https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits/description/


// Solution //
class Solution {
    public:
        int maximumSum(vector<int>& nums) {
            int maxSum = -1;
            unordered_map<int, pair<int,int>> mpp;
            for(auto &num : nums){
                int digitSum = getDigitSum(num);
                auto &[max1, max2] = mpp[digitSum];
                if( num >= max1 ){
                    max2 = max1;
                    max1 = num;
                } else if( num > max2 ){
                    max2 = num;
                }
                int sum = (max1==0 || max2==0)? -1 : max1+max2;
                maxSum = max(maxSum, sum);
            }
            return maxSum;
        }
    private:
        int getDigitSum(int num){
            int sum = 0;
            while( num > 0 ){
                sum += (num%10);
                num /= 10;
            }
            return sum;
        }
    };