// Problem Link : https://leetcode.com/problems/candy/description/


// Solution //
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int candies[n], start = 0;
        for(int i=1;i<n;i++){
            if( ratings[i] > ratings[i-1] ){
                distributeCandies(ratings, candies, start, i-1);
                start = i;
            }
        }
        distributeCandies(ratings, candies, start, n-1);
        return accumulate(candies, candies+n, 0);
    }

    void distributeCandies(vector<int>& ratings, int candies[], int start, int end){
        int candy = 1;
        for(int idx=end; idx>start; idx--){
            candies[idx] = candy;
            candy = ratings[idx] == ratings[idx-1]? 1 : candy+1;
        }
        if( start == 0 ){
            candies[start] = candy;
        } else{
            candies[start] = max(candies[start-1]+1, candy);
        }
    }
};