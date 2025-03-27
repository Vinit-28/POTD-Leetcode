// Problem Link : https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/description/


// Solution //
class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> arr;
        for(auto &row: grid){
            arr.insert(arr.end(), begin(row), end(row));
        }
        sort(begin(arr), end(arr));
        int rem = arr[0]%x;
        int ops = 0;
        int midEle = arr[((int)arr.size())/2];
        for(auto &ele: arr){
            if( rem != (ele%x) ) return -1;
            ops += (abs(midEle-ele)/x);
        }
        return ops;
    }
};