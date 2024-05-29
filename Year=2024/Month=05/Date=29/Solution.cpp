// Problem Link : https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/description/


// Solution //
class Solution {
public:
    int numSteps(string s) {
        int carry = 0;
        int n = s.length();
        int steps = 0;
        for(int i=n-1; i>0; i--){
            if( s[i] == '0' && carry == 0 ){ // Pure Even //
                steps += 1;
            } else if( s[i] == '1' && carry == 0 ){ // Pure Odd //
                steps += 2;
                carry = 1;
            } else if( s[i] == '0' && carry == 1 ){ // Converted Odd //
                steps += 2;
            } else if( s[i] == '1' && carry == 1 ){ // Converted Even //
                steps += 1;
            }
        }
        steps += carry;
        return steps;
    }
};