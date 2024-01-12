// Problem Link : https://leetcode.com/problems/determine-if-string-halves-are-alike/description/


// Solution //
class Solution {
public:
    bool isVowel(char ch){
        ch = !(ch>='a'&&ch<='z')? ch+32 : ch;
        return (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u');
    }

    bool halvesAreAlike(string s) {
        int n = s.length(), mid = n/2;
        int count = 0;
        for(int i=0;i<n;i++){
            if( isVowel(s[i]) ){
                count += (i<mid)? 1 : -1;
            }
        }
        return count==0;
    }
};