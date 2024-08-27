// Problem Link : https://leetcode.com/problems/ugly-number-ii/description/



// Solution //
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ugly = {1};
        int two = 0, three = 0, five = 0;
        for(int idx=0; idx<n-1; idx++){
            int val1 = ugly[two] * 2;
            int val2 = ugly[three] * 3;
            int val3 = ugly[five] * 5;
            if( val1 <= val2 && val1 <= val3 ){
                ugly.push_back(val1);
                two += 1;
                if( val1 == val2 ) three += 1;
                if( val1 == val3 ) five += 1;
            } else if( val2 <= val1 && val2 <= val3 ){
                ugly.push_back(val2);
                three += 1;
                if( val2 == val3 ) five += 1;
            } else{
                ugly.push_back(val3);
                five += 1;
            }
        }
        return ugly.back();
    }
};