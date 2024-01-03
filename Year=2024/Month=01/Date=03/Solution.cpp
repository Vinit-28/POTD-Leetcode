// Problem Link : https://leetcode.com/problems/number-of-laser-beams-in-a-bank/description/


// Solution //
class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int lastSum = 0, currSum;
        int totalBeams = 0;
        for(auto &row : bank){
            currSum = getOneCount(row);
            totalBeams += (currSum * lastSum);
            lastSum = currSum>0? currSum : lastSum;
        }
        return totalBeams;
    }

    int getOneCount(string &s){
        int count = 0;
        for(auto &ch : s){
            count += ch=='1';
        }
        return count;
    }
};