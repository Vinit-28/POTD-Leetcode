// Problem Link : https://leetcode.com/problems/count-total-number-of-colored-cells/description/


// Solution //
class Solution {
public:
    long long coloredCells(int n) {
        long long ans = 1;
        for(long long i=1; i<n; i++){
            ans += (4 * i);
        }
        return ans;
    }
};