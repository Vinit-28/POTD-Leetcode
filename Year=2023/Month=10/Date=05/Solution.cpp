// Problem Link : https://leetcode.com/problems/majority-element-ii/description/


// Solution //
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size(), ele1 = INT_MAX, ele2 = INT_MAX;
        int freq1 = 0, freq2 = 0;
        vector<int> ans;
        for(auto &ele : nums){
            if( ele1 == ele ){
                freq1 += 1;
            } else if( ele2 == ele ){
                freq2 += 1;
            } else if( ele1 == INT_MAX ){
                ele1 = ele, freq1 = 1;
            } else if( ele2 == INT_MAX ){
                ele2 = ele, freq2 = 1;
            } else{
                if( freq2 <= 0 ){
                    ele2 = ele, freq2 = 1;
                } else if( freq1 <= 0 ){
                    ele1 = ele, freq1 = 1;
                } else{
                    freq1 -= 1, freq2 -= 1;
                }
            }
        }
        freq1 = freq2 = 0;
        for(auto &ele : nums){
            if( ele == ele1 ) freq1 += 1;
            else if( ele == ele2 ) freq2 += 1;
        }
        if( freq1 > (n/3) ) ans.push_back(ele1);
        if( freq2 > (n/3) ) ans.push_back(ele2);
        return ans;
    }
};