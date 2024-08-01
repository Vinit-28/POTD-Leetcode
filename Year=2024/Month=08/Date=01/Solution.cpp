// Problem Link : https://leetcode.com/problems/number-of-senior-citizens/description/


// Solution //
class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0;
        for(auto &str : details){
            int age = (str[11]-'0')*10+(str[12]-'0');
            if( age > 60 ) count += 1;
        }
        return count;
    }
};