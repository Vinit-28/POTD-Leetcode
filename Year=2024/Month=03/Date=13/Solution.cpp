// Problem Link : https://leetcode.com/problems/find-the-pivot-integer/description/

// Solution //
class Solution {
public:
    int pivotInteger(int n) {
        int l = 1, u = n;
        int totalSum = (n*(n+1))/2;
        while( l<=u ){
            int mid = (l+u)/2;
            int leftSum = (mid * (mid+1))/2;
            int rightSum = (totalSum - leftSum + mid);
            if( leftSum == rightSum ){
                return mid;
            } else if( leftSum < rightSum ){
                l = mid+1;
            } else{
                u = mid-1;
            }
        }
        return -1;
    }
};