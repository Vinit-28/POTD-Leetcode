// Problem Link : https://leetcode.com/problems/buy-two-chocolates/description/


// Solution //
class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int min1= INT_MAX, min2 = INT_MAX;
        for(auto &price : prices){
            if( price < min1 ){
                min2 = min1, min1 = price;
            } else if( min2 > price ){
                min2 = price;
            }
        }
        return (min1 + min2) > money? money : money - (min1 + min2);
    }
};