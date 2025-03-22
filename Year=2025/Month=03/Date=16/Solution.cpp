// Problem Link : https://leetcode.com/problems/minimum-time-to-repair-cars/description/


// Solution //
using ll = long long;
class Solution {
public:
    ll repairCars(vector<int>& ranks, int cars) {
        ll l = -1, u = (ll)1e16;
        while( l+(ll)1 < u ){
            ll mid = (l+u)/(ll)2;
            if( isPossible(ranks, cars, mid) ){
                u = mid;
            } else{
                l = mid;
            }
        }  
        return u;
    }
private:
    bool isPossible(vector<int> &ranks, ll cars, ll mid){
        for(auto &rank: ranks){
            ll n = (ll)sqrt(mid*1.0/(ll)rank);
            cars -= n;
        }
        return cars<=0;
    }
};