// Problem Link : https://leetcode.com/problems/calculate-money-in-leetcode-bank/description/

// Solution //
class Solution {
public:
    int totalMoney(int n) {
        int money = 1;
        int totalMoney = 0;
        for(int i=1;i<=n;i++){
            totalMoney += money;
            if( i%7 == 0 ){
                money = (i/7)+1;
            } else{
                money += 1;
            }
        }
        return totalMoney;
    }
};
