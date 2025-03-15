// Problem Link : https://leetcode.com/problems/maximum-candies-allocated-to-k-children/description/


// Solution //
using ll = long long;
class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        ll l = 0, u = ll(INT_MAX)+1;
        function<bool(ll mid)> isPossible = [&] (ll mid)->bool{
            ll childs = 0;
            for(auto &c: candies){
                childs += (c/mid);
            }
            return childs >= k;
        };
        while( l+1 < u ){
            ll mid = (l+u)/2;
            if( isPossible(mid) ){
                l = mid;
            } else{
                u = mid;
            }
        }
        return l;
    }
};