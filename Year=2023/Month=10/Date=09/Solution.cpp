// Problem Link : https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/


// Solution //
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int first = search(nums, target, 0, n-1, 'l');
        int last = first == -1? -1 : search(nums, target, first, n-1, 'r');
        return {first, last};
    }

    int search(vector<int> &nums, int target, int l, int u, char dir){
        int m = (l+u)/2, idx = -1;
        while( l<=u ){
            if( nums[m] == target ){
                if( dir == 'r' ){
                    l = m+1;
                } else if( dir == 'l' ){
                    u = m-1;
                }
                idx = m;
            } else if( nums[m] > target ){
                u = m-1;
            } else{
                l = m+1;
            }
            m = (l+u)/2;
        }
        return idx;
    }
};