// Problem Link : https://leetcode.com/problems/sequential-digits/description/


// Solution //
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        int startDigits = to_string(low).size();
        int endDigits = to_string(high).size();
        vector<int> ans;
        for(int d=startDigits;d<=endDigits;d++){
            for(int first=1;first<=(9-d+1);first++){
                helper(first, d-1, low, high, ans);
            }
        }
        return ans;
    }

    void helper(int num, int digitsLeft, int &low, int &high, vector<int> &ans){
        if( num > high || (num%10==9 && digitsLeft > 0) ) return;
        if( digitsLeft == 0 ){
            if( num >= low && num <= high ){
                ans.push_back(num);
            } 
        } else{
            int lastDigit = num%10;
            helper((num*10)+(lastDigit+1), digitsLeft-1, low, high, ans);
        }
    }
};