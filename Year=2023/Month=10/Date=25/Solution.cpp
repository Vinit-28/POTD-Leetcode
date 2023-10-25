// Problem Link : https://leetcode.com/problems/k-th-symbol-in-grammar/description/


// Solution //
class Solution {
public:
    int kthGrammar(int n, int k) {
        if( k==1 || n==1 ){
            return 0;
        }
        return solve(n, k);
    }

    int solve(int n, int k){
        if( n == 2 ){
            return k==n;
        } else{
            int totalChars = (1<<(n-1));
            int half = totalChars / 2;
            if( k <= half ){
                return solve(n-1, k);
            } else{
                return !solve(n-1, k-half);
            }
        }
        return 0;
    }
};