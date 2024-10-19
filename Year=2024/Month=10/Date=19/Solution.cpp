// Problem Link : https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/description/


// Solution //
class Solution {
public:
    char findKthBit(int n, int k) {
        if( n==1 || k==1 ) return '0';
        int mid = (1<<(n-1));
        if( k == mid ){
            // Middle guy will always be '1', as mentioned in the question
            // leftPart + "1" + rightPart
            return '1';
        } else if( k < mid ){
            // If kth bit exists in the left part, simply
            // ask the answer from the left
            return findKthBit(n-1, k);
        } else{
            // If the kth bit exists in the right part, then remember how
            // we made the right part from the left part itself by doing 2 operations
            // that is Invert & Reverse, so let's do the same
            // Reverse: kth bit from the start in right part would become kth bit from the end
            // in left part.
            // Invert: If the kth bit in left part was '1' it would become '0' in right part or 
            // vice versa.
            return findKthBit(n-1, (1<<n)-k)=='0'? '1' : '0';
        }
    }
};