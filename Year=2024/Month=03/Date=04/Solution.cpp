// Problem Link : https://leetcode.com/problems/bag-of-tokens/description/


// Solution //
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int left = 0, right = tokens.size()-1;
        int score = 0, maxScore = 0;
        while( left <= right ){
            if( power >= tokens[left] ){
                power -= tokens[left];
                left += 1;
                score += 1;
            } else if( score > 0 ){
                power += tokens[right];
                right -= 1;
                score -= 1;
            } else{
                break;
            }
            maxScore = max(maxScore, score);
        }
        return maxScore;
    }
};