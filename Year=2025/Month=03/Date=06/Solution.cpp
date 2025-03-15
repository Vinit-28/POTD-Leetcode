// Problem Link : https://leetcode.com/problems/find-missing-and-repeated-values/description/


// Solution //
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int ax = 0, gx = 0;
        int n = grid.size();
        int count = 1;

        for(auto &row : grid){
            for(auto &val: row){
                gx = gx xor val;
                ax = ax xor count++;
            }
        }
        int both = ax xor gx;
        int bitIdx = __builtin_ffs(both)-1;
        int gb1 = 0, gb2 = 0;
        int ab1 = 0, ab2 = 0;
        count = 1;

        for(auto &row : grid){
            for(auto &val : row){
                int bit = (val>>bitIdx)&1;
                if( bit == 0 ) gb1 = gb1 xor val;
                else gb2 = gb2 xor val;
                
                bit = (count>>bitIdx)&1;
                if( bit == 0 ) ab1 = ab1 xor count++;
                else ab2 = ab2 xor count++;
            }
        }
        int first = ab1 xor gb1;
        int second = ab2 xor gb2;

        for(auto &row : grid){
            for(auto &val : row){
                if( val == first ) return {first, second};
                if( val == second ) return {second, first};
            }
        }
        return {};
    }
};