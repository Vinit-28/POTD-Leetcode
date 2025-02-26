// Problem Link : https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/description/


// Solution //
using ll = long long;
ll MOD = 1e9+7;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        ll ans = 0;
        ll odd = 0, even = 0;
        for(auto &ele : arr){
            ll newOdd, newEven;
            if( ele&1 ){
                newOdd = (even + 1)%MOD;
                newEven = (odd)%MOD;
            } else{
                newOdd = (odd)%MOD;
                newEven = (even + 1)%MOD;
            }
            odd = newOdd;
            even = newEven;
            ans = (ans + odd)%MOD;
        }        
        return ans;
    }
};