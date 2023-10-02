// Problem Link : https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color/description/


// Solution //
class Solution {
public:
    bool winnerOfGame(string colors) {
        int alice = 0, bob = 0, count = 0;
        char prevColor = '0';
        for(auto &color : colors){
            if( prevColor == '0' ){
                prevColor = color;
                count = 1;
            } else if( prevColor == color ){
                count += 1;
            } else{
                if( prevColor == 'A' ){
                    alice += max(0, count-2);
                } else{
                    bob += max(0, count-2);
                }
                prevColor = color;
                count = 1;
            }
        }
        if( prevColor == 'A' ){
            alice += max(0, count-2);
        } else{
            bob += max(0, count-2);
        }
        return alice > bob;
    }
};