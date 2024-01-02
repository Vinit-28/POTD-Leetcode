// Problem Link : https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/description/


// Solution1 //
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        map<int, int> hmap; // { {element: max_row_size}, } //
        int maxRow = 0;
        vector<vector<int>> mat;
        for(auto &ele : nums){
            maxRow = max(maxRow, ++hmap[ele]);
        }
        mat.resize(maxRow, vector<int>());
        for(auto &p : hmap){
            for(int i=0;i<p.second;i++){
                mat[i].push_back(p.first);
            }
        }
        return mat;
    }
};