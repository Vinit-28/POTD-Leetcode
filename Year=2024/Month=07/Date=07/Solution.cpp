// Problem Link : https://leetcode.com/problems/water-bottles/description/


// Solution //
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        return numBottles + (numBottles-1)/(numExchange-1);
    }
};