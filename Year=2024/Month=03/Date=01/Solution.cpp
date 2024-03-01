// Problem Link : https://leetcode.com/problems/maximum-odd-binary-number/description/


// Solution //
class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int one = 0, n = s.size();
        for(auto &ch : s){
            if( ch == '1' ) one += 1;
        }
        string newS = "";
        for(int i=0;i<n-1;i++){
            if( one <= 1 ){
                newS += "0";
            } else{
                newS += "1";
                one -= 1;
            }
        }
        return newS + "1";
    }
};