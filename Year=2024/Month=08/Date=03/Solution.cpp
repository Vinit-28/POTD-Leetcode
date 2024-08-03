// Problem Link : https://leetcode.com/problems/make-two-arrays-equal-by-reversing-subarrays/description/


// Solution //
class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int mpp[1001] = {0};
        for(auto &ele : arr) mpp[ele] += 1;
        for(auto &ele : target) mpp[ele] -= 1;
        for(int i=0; i<1001; i++) if( mpp[i] != 0 ) return false;
        return true;
    }
};