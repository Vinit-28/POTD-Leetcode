// Problem Link : https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/description/


// Solution //
class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0;
        int need = 0;
        for(auto &ch : s){
            if( ch == '(' ){
                open += 1;
            } else if( open > 0 ){
                open -= 1;
            } else{
                need += 1;
            }
        }
        return open + need;
    }
};