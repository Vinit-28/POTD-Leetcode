// Problem Link : https://leetcode.com/problems/adding-spaces-to-a-string/description/


// Solution //
class Solution {
    public String addSpaces(String s, int[] spaces) {
        StringBuilder sb = new StringBuilder("");
        int idx = 0;
        for(int i=0; i<s.length(); i++){
            if( idx >= spaces.length || i < spaces[idx] ){
                sb.append(s.charAt(i));
            } else if( idx < spaces.length ){
                sb.append(' ');
                sb.append(s.charAt(i));
                idx += 1;
            }
        }
        return sb.toString();
    }
}