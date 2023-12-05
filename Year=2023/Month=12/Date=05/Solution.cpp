// Problem Link : https://leetcode.com/problems/count-of-matches-in-tournament/description/


// Solution //
class Solution {
public:
    int numberOfMatches(int n) {
        return n<2? 0 : (n/2 + ((n&1)? numberOfMatches(n/2+1) : numberOfMatches(n/2))); 
    }
};
