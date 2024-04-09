// Problem Link : https://leetcode.com/problems/time-needed-to-buy-tickets/description/


// Solution //
class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int leftSum = 0;
        int rightSum = 0;
        for(int i=0;i<tickets.size();i++){
            if( i<k ){
                leftSum += min(tickets[i], tickets[k]);
            } else if( i>k ){
                rightSum += min(tickets[i], tickets[k]-1);
            }
        }
        return leftSum + tickets[k] + rightSum;
    }
};