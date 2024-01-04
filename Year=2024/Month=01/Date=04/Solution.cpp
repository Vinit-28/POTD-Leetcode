// Problem Link : https://leetcode.com/problems/minimum-number-of-operations-to-make-array-empty/description/


// Solution //
class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int, int> hmap;
        int ops = 0;
        for(auto &ele : nums){
            hmap[ele] += 1;
        }
        for(auto &p : hmap){
            if( p.second == 1 ) return -1;
            int mod = p.second%3;
            ops += mod==0? p.second/3 : p.second/3+1;
        }
        return ops;
    }
};