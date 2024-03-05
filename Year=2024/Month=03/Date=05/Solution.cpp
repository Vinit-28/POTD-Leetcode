// Problem Link : https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/description/


// Solution //
class Solution {
    public int minimumLength(String s) {
        int length = s.length();
        int left = 0, right = length-1;
        while( left<right ){
            if( s.charAt(left) != s.charAt(right) ){
                break;
            } else{
                int start = left, end = right;
                while( start < right && s.charAt(start) == s.charAt(left) ){
                    start += 1;
                }
                while( end > start && s.charAt(end) == s.charAt(right) ){
                    end -= 1;
                }
                left = start;
                right = end;
            }
        }
        if( left == right ){
            if( left == 0 || s.charAt(left) != s.charAt(left-1) ){
                return 1;
            } else{
                return 0;
            }
        }
        return (right-left+1);
    }
}