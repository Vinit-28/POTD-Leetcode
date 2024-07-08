// Problem Link : https://leetcode.com/problems/find-the-winner-of-the-circular-game/description/


// Solution //
class Solution {
public:
    int findTheWinner(int n, int k) {
        int winner = 1;
        for(int round=2; round<=n; round++){
            int currLooser = (k%round==0? round : k%round);
            int finalIdx = currLooser + winner;
            int currWinner = (finalIdx%round==0? round : finalIdx%round);
            winner = currWinner;
        }
        return winner;
    }
};