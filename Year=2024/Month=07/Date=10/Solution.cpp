// Problem Link : https://leetcode.com/problems/crawler-log-folder/description/


// Solution //
class Solution {
public:
    int minOperations(vector<string>& logs) {
        int nested = 0;
        for(auto &log :logs){
            if( log == "../" ){
                nested -= (nested==0? 0 : 1);
            } else if( log == "./" ){
                continue;
            } else{
                nested += 1;
            }
        }
        return nested;
    }
};