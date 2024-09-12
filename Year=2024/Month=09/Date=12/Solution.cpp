// Problem Link : https://leetcode.com/problems/count-the-number-of-consistent-strings/description/


// Solution //
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        set<char> ac(begin(allowed), end(allowed));
        int count = 0;
        for(auto &word : words){
            bool flag = true;
            for(auto &ch : word){
                if( !ac.count(ch) ){
                    flag = false;
                    break;
                }
            }
            count += flag;
        }
        return count;
    }
};