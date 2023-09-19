// Problem Link : https://leetcode.com/problems/find-the-duplicate-number/description/


// Solution //
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0], fast = nums[0], val = nums[0];
        do{
            slow = nums[slow]; // moving with the speed of 1 //
            fast = nums[nums[fast]]; // moving with the speed of 2 //
        } while( slow != fast );
        // Finding the origin //
        while( val != slow ){
            val = nums[val];
            slow = nums[slow];
        }
        return val;
    }
};