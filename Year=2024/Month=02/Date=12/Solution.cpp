// Problem Link : https://leetcode.com/problems/majority-element/description/


// Solution //
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int freq = 0, num = -1;
        for(auto &ele :nums){
            if( ele != num ) freq -= 1;
            else if( ele == num ) freq += 1;
            if( freq < 0 ) num = ele, freq = 1;
        }
        return num;
    }
};
