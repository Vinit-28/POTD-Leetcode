// Problem Link : https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/description/


// Solution //
class Solution {
private:
    vector<char> charSet = {'a', 'b', 'c'};
    string ans;
public:
    string getHappyString(int n, int k) {
        string s = "";
        helper(n, k, s);
        return ans;
    }
private:
    void helper(int n, int &k, string &s){
        if( k == 0 ) return;
        if( n == 0 ){
            if( --k == 0 ){
                ans = s;
            }
        } else{
            for(auto &ch : charSet){
                if( s.empty() || s.back() != ch ){
                    s.push_back(ch);
                    helper(n-1, k, s);
                    s.pop_back();
                }
            }
        }
    }
};