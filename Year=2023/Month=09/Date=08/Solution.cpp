// Problem Link : https://leetcode.com/problems/pascals-triangle/


// Solution //
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
       
        vector<vector<int>> ans;
        for(int r=1;r<=numRows;r++){
            vector<int> row;
            for(int c=0;c<r;c++){
                if( c==0 || c==(r-1) ) row.push_back(1);
                else{
                    row.push_back(ans[r-2][c-1] + ans[r-2][c]);
                }
            }
            ans.push_back(row);
        }
        return ans;
    }
};