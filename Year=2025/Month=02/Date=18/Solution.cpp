// Problem Link : https://leetcode.com/problems/construct-smallest-number-from-di-string/description/


// Solution //
class Solution {
private:
    string ans;
public:
    string smallestNumber(string pattern) {
        string num = "";
        vector<bool> isUsed(10, false);
        helper(pattern, 0, num, isUsed);
        return ans;
    }
private:
    bool helper(string &p, int idx, string &num, vector<bool> &isUsed){
        if( idx > p.size() ){
            ans = num;
            return true;
        } else{
            char start, end;
            if( idx == 0 ) start = '1', end = '9';
            else{
                if( p[idx-1] == 'I' ) start = (num.back()+1), end = '9';
                else start = '1', end = (num.back()-1);
            }
            for(char ele=start; ele<=end; ele++){
                if( !isUsed[ele-'0'] ){
                    num.push_back(ele);
                    isUsed[ele-'0'] = true;
                    if( helper(p, idx+1, num, isUsed) ) return true;
                    num.pop_back();
                    isUsed[ele-'0'] = false;
                }
            }
            return false;
        }
    }
};