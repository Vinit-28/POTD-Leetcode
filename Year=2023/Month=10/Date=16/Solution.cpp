// Problem Link : https://leetcode.com/problems/pascals-triangle-ii/description/


// Solution //
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if( rowIndex == 0 ) return {1};
        vector<int> curr, nxt;
        curr = {1};
        for(int i=1;i<=rowIndex;i++){
            nxt = vector<int>(i+1, 0);
            for(int j=0;j<i;j++){
                nxt[j] += curr[j];
                nxt[j+1] += curr[j];
            }
            curr = nxt;
        }
        return curr;
    }
};