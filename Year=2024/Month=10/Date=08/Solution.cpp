// Problem Link : https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/description/


// Solution //
class Solution {
public:
    int minSwaps(string s) {
        int misplaced = 0;
        int open = 0;
        for(auto &ch : s){
            if( ch == '[' ) open += 1;
            else if( open > 0 ) open -= 1;
            else misplaced += 1;
        }
        return ceil(misplaced*1.0/2);
    }
};