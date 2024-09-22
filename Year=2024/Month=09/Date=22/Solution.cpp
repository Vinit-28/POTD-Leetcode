// Problem Link : https://leetcode.com/problems/k-th-smallest-in-lexicographical-order/description/


// Solution //
using ll = long long;
class Solution {
private:
    ll getChildsCount(ll n, ll num){
        ll levelStart = num, levelEnd = num+1;
        ll childs = 0;
        while( levelStart <= n ){
            ll nodes = min(n+1, levelEnd) - levelStart;
            childs += nodes;
            levelStart *= 10; // Next level of the same node //
            levelEnd *= 10; // Next level of the same node //
        }
        return childs;
    }

public:
    int findKthNumber(int n, int k) {
        ll num = 1;
        k -= 1; // For current number 1 //
        while( k > 0 ){
            ll childs = getChildsCount(n, num);
            if( childs <= k ){
                k -= childs;
                num += 1; // Going to next sibbling 1 -> 2 -> 3, 101 -> 102, 403 -> 404 //
            } else{
                num *= 10; // Going deep in the current level 1 -> 10, 100 -> 1000, 30 -> 300 //
                k -= 1; // For current number //
            }
        }
        return num;
    }
};