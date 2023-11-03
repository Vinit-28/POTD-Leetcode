// Problem Link : https://leetcode.com/problems/build-an-array-with-stack-operations/description/


// Solution //
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int extra = 0;
        int streamTop = 1;
        vector<string> operations;
        for(auto &ele : target){
            while( streamTop < ele ){
                streamTop += 1;
                extra += 1;
            }
            if( streamTop == ele ){
                for(int i=0;i<extra;i++) operations.push_back("Push");
                for(int i=0;i<extra;i++) operations.push_back("Pop");
                operations.push_back("Push");
                streamTop += 1;
                extra = 0;
            }
        }
        return operations;
    }
};