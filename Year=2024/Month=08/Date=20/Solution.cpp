// Problem Link : https://leetcode.com/problems/stone-game-ii/description/



// Solution //
class Solution {
public:
    int dp[101][301][2];
    int stoneGameII(vector<int>& piles) {
        memset(dp, -1, sizeof(dp));
        return helper(piles, 0, 1, 0);
    }

    int helper(vector<int> &piles, int idx, int m, int choice){
        if( idx >= piles.size() ){
            return 0;
        } else if( dp[idx][m][choice] == -1 ){
            int sum = 0;
            int maxScore = INT_MIN;
            int minScore = INT_MAX;
            int limit = min(2*m, int(piles.size())-idx);
            for(int x=0; x<limit; x++){
                sum += piles[idx+x];
                if( choice == 0 ){
                    maxScore = max(maxScore, sum + helper(piles, idx+x+1, max(x+1, m), 1));
                } else{
                    minScore = min(minScore, helper(piles, idx+x+1, max(x+1, m), 0));
                }
            }
            dp[idx][m][choice] = choice==0? maxScore : minScore;
        }
        return dp[idx][m][choice];
    }
};