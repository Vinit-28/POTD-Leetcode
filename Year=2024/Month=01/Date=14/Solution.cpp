// Problem Link : https://leetcode.com/problems/determine-if-two-strings-are-close/description/


// Solution //
class Solution {
public:
    bool closeStrings(string w1, string w2) {
        if( w1.size() != w2.size() ) return false;
        int h1[26]={0}, h2[26]={0};
        map<int, int> freqCount1, freqCount2;
        int n = w1.size();
        for(int i=0;i<n;i++){
            h1[w1[i]-'a'] += 1;
            h2[w2[i]-'a'] += 1;
        }
        for(int i=0;i<26;i++){
            if( h1[i] != h2[i] && (h1[i]==0 || h2[i]==0) ) return false;
            freqCount1[h1[i]] += 1;
            freqCount2[h2[i]] += 1;
        }
        for(auto &p : freqCount1){
            if( p.second != freqCount2[p.first] ){
                return false;
            }
        }
        return true;
    }
};