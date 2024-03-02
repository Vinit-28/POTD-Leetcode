// Problem Link : https://leetcode.com/problems/squares-of-a-sorted-array/description/


// Solution //
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        int posIdx = n;
        for(int i=0;i<n;i++){
            if( nums[i] >= 0 ){
                posIdx = i;
                break;
            }
        }
        int negIdx = posIdx - 1;
        while( negIdx>=0 || posIdx<n ){
            if( negIdx<0 || (posIdx<n && getSq(nums[posIdx]) < getSq(nums[negIdx])) ){
                ans.push_back(getSq(nums[posIdx++]));
            } else{
                ans.push_back(getSq(nums[negIdx--]));
            }
        }
        return ans;
    }

    int getSq(int n){
        return n*n;
    }
};