// Problem Link : https://leetcode.com/problems/remove-all-occurrences-of-a-substring/description/


// Solution //
class Solution {
public:
    string removeOccurrences(string s, string part) {
        string res = "";
        for(auto &ch : s){
            res.push_back(ch);
            removeIfNeeded(res, part);
        }
        return res;
    }
private:
    void removeIfNeeded(string &str, string &part){
        if( isNeedToRemove(str, part) ){
            int toRemove = part.size();
            while( toRemove-- > 0 ){
                str.pop_back();
            }
        }
    }

    bool isNeedToRemove(string &str, string &part){
        if( str.size() < part.size() ) return false;
        int idx1 = str.size()-1;
        int idx2 = part.size()-1;
        while( idx2 >= 0 && str[idx1] == part[idx2] ){
            idx1 -= 1;
            idx2 -= 1;
        }
        return idx2==-1;
    }
};