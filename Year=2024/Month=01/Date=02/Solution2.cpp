// Problem Link : https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/description/


// Solution2 //
class Solution {
public:
    void pushElement(vector<vector<int>> &mat, int &ele, int count){
        for(int j=1;j<=count;j++){
            if( j > mat.size() ){
                mat.push_back({});
            }
            mat[j-1].push_back(ele);
        }
    }

    vector<vector<int>> findMatrix(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> mat;
        int count = 1, n = nums.size();
        for(int i=1;i<n;i++){
            if( nums[i] == nums[i-1] ){
                count += 1;
            } else{
                pushElement(mat, nums[i-1], count);
                count = 1;
            }
        }
        pushElement(mat, nums[n-1], count);
        return mat;
    }
};