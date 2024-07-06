// Problem Link : https://leetcode.com/problems/pass-the-pillow/description/


// Solution //
class Solution {
public:
    int passThePillow(int n, int time) {
        int cycle = n-1;
        int cycles = time/cycle;
        int rem = time%cycle;
        return (cycles&1)? n-rem : rem+1;
    }
};