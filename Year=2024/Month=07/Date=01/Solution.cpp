// Problem Link : https://leetcode.com/problems/three-consecutive-odds/description/


// Solution //
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int sum = 0;
        for(auto &ele : arr){
            sum = ele&1? sum + 1 : 0;
            if( sum == 3 ) return true;
        }
        return false;
    }
};