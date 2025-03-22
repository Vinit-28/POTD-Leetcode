// Problem Link : https://leetcode.com/problems/divide-array-into-equal-pairs/description/


// Solution //
class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int mpp[501] = {0};
        for(auto &ele : nums) mpp[ele] += 1;
        for(int i=1; i<501; i++){
            if( mpp[i]&1 ) return false;
        }
        return true;
    }
};