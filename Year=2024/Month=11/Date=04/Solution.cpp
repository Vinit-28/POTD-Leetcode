// Problem Link : https://leetcode.com/problems/string-compression-iii/description/


// Solution //
class Solution {
public:
    string compressedString(string word) {
        vector<pair<int,char>> arr;
        int f = 1;
        int n = word.size();
        string comp = "";
        for(int i=1; i<n; i++){
            if( word[i] != word[i-1] ){
                arr.push_back({f, word[i-1]});
                f = 0;
            }
            f += 1;
        }
        arr.push_back({f, word[n-1]});
        for(auto [freq, c]: arr){
            while( freq > 0 ){
                if( freq < 9 ) comp += (to_string(freq) + c);
                else comp += (to_string(9) + c);
                freq -= 9;
            }
        }
        return comp;
    }
};