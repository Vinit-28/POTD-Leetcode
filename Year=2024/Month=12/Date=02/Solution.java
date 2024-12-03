// Problem Link : https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/description/


// Solution //
class Solution {
    public int isPrefixOfWord(String sentence, String searchWord) {
        int idx = 1;
        for(String str : sentence.split("\\s+")){
            if( str.startsWith(searchWord) ) return idx;
            idx += 1;
        }
        return -1;
    }
}