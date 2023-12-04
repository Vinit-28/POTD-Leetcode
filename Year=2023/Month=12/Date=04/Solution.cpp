// Problem Link : https://leetcode.com/problems/largest-3-same-digit-number-in-string/description/


// Solution //
class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();
        string maxi = "";
        for(int i=0;i<n-2;i++){
            if( num[i] == num[i+1] && num[i+1] == num[i+2] ){
                string str = num.substr(i, 3);
                maxi = max(maxi, str);
            }
        }
        return maxi;
    }
};