// Problem Link : https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/


// Solution //
class Solution {
public:
    int countOrders(int n) {
        int ans = 1;
        long mod = 1e9+7;
        for(int i=2;i<=n;i++){
            int prevAns = ans % mod;
            int places = (i-1)*2;
            int combsPerPrevComb = ((places * (places+1))/2) + places+1;
            ans = ((combsPerPrevComb % mod) * (prevAns % mod)) % mod;
        }
        return ans % mod;
    }
};