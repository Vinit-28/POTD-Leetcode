// Problem Link : https://leetcode.com/problems/make-string-a-subsequence-using-cyclic-increments/description/


// Solution //
class Solution {
    public boolean canMakeSubsequence(String str1, String str2) {
        int idx1 = str1.length()-1;
        int idx2 = str2.length()-1;
        while( idx1 >= 0 && idx2 >= 0 ){
            char c1 = str1.charAt(idx1);
            char c2 = str2.charAt(idx2);
            if( c1==c2 || (int)(c2-c1)==1 || (c1=='z' && c2=='a') ){
                idx2 -= 1;
            }
            idx1 -= 1;
        }
        return idx2==-1;
    }
}