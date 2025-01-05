// Problem Link : https://leetcode.com/problems/shifting-letters-ii/description/


// Solution //
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        int prefixSum[n+1];
        memset(prefixSum, 0, sizeof(prefixSum));
        for(auto &shift : shifts){
            int l = shift[0], r = shift[1], inc = shift[2]==0? -1 : 1;
            prefixSum[l] += inc;
            prefixSum[r+1] -= inc;
        }
        int sum = 0;
        for(int idx=0; idx<n; idx++){
            sum += prefixSum[idx];
            s[idx] = getShiftedChar(s[idx], sum);
        }
        return s;
    }

private:
    char getShiftedChar(char ch, int shiftBy){
        bool back = shiftBy<0;
        shiftBy = abs(shiftBy)%26;
        if( back ){
            int diff = ch-'a';
            if( diff >= shiftBy ) ch -= shiftBy;
            else ch = 'z'-(shiftBy-diff-1);
        } else{
            int curr = ch-'a';
            curr = (curr + shiftBy)%26;
            ch = 'a'+curr;
        }
        return ch;
    }
};