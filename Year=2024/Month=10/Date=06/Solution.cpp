// Problem Link : https://leetcode.com/problems/sentence-similarity-iii/description/


// Solution //
class Solution {
private:
    vector<string> split(string &str, char del){
        string s = "";
        vector<string> arr;
        for(auto &ch : str){
            if( ch == ' ' ){
                arr.push_back(s);
                s = "";
            } else{
                s += ch;
            }
        }
        arr.push_back(s);
        return arr;
    }

    bool helper1(vector<string> &s1, vector<string> &s2){
        int m = s1.size(), n = s2.size();
        int i = 0, j = 0;
        bool match = true;
        int mismatchCount = 0;
        while( i<m && j<n ){
            if( s1[i] == s2[j] ){
                i += 1;
                j += 1;
                match = true;
            } else{
                j += 1;
                if( match ) mismatchCount += 1;
                match = false;
            }
            if( mismatchCount > 1 ){
                return false;
            }
        }
        if( j < n && (match && mismatchCount >= 1) ) return false;
        return i>=m;
    }

    bool helper2(vector<string> &s1, vector<string> &s2){
        int m = s1.size(), n = s2.size();
        int i = m-1, j = n-1;
        bool match = true;
        int mismatchCount = 0;
        while( i>=0 && j>=0 ){
            if( s1[i] == s2[j] ){
                i -= 1;
                j -= 1;
                match = true;
            } else{
                j -= 1;
                if( match ) mismatchCount += 1;
                match = false;
            }
            if( mismatchCount > 1 ){
                return false;
            }
        }
        if( j >= 0 && (match && mismatchCount >= 1) ) return false;
        return i==-1;
    }
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> s1 = split(sentence1, ' ');
        vector<string> s2 = split(sentence2, ' ');
        return helper1(s1, s2) || helper2(s1, s2) || helper1(s2, s1) || helper2(s2, s1);
    }
};